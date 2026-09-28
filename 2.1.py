from math import radians, sin, cos, asin, sqrt
from itertools import combinations
from bs4 import BeautifulSoup

# Файл карты и ключевые слова для поиска вуза в нём
FILES = {
    'ВВГУ': ('map_vvgu.xml', ['ВГУЭС', 'ВВГУ', 'Владивостокский государственный университет']),
    'ТГМУ': ('map_tgmu.xml', ['ТГМУ', 'Тихоокеанский государственный медицинский']),
    'ДВФУ': ('map_dvfu.xml', ['ДВФУ', 'Дальневосточный федеральный']),
}


def haversine(p1, p2):
    """Расстояние между двумя точками (lat, lon) в метрах."""
    R = 6371000
    lat1, lon1, lat2, lon2 = map(radians, (*p1, *p2))
    a = sin((lat2 - lat1) / 2) ** 2 + cos(lat1) * cos(lat2) * sin((lon2 - lon1) / 2) ** 2
    return 2 * R * asin(sqrt(a))


def load(filename):
    xml = open(filename, 'r', encoding='utf8').read()
    return BeautifulSoup(xml, 'xml')


def tags_of(el):
    return {t['k']: t['v'] for t in el.find_all('tag', recursive=False)}


def center(el, nodes, ways):
    """Координаты объекта: у точки берём lat/lon, у здания/территории — среднее по её точкам."""
    if el.name == 'node':
        return float(el['lat']), float(el['lon'])
    if el.name == 'way':
        pts = [nodes[nd['ref']] for nd in el.find_all('nd') if nd['ref'] in nodes]
    else:  # relation — собираем точки всех её линий
        pts = []
        for m in el.find_all('member'):
            if m['type'] == 'way' and m['ref'] in ways:
                pts += ways[m['ref']]
            elif m['type'] == 'node' and m['ref'] in nodes:
                pts.append(nodes[m['ref']])
    if not pts:
        return None
    return sum(p[0] for p in pts) / len(pts), sum(p[1] for p in pts) / len(pts)


def find_university(filename, keywords):
    soup = load(filename)
    nodes = {n['id']: (float(n['lat']), float(n['lon'])) for n in soup.find_all('node')}
    ways = {w['id']: [nodes[nd['ref']] for nd in w.find_all('nd') if nd['ref'] in nodes]
            for w in soup.find_all('way')}

    best, best_score = None, -1
    for el in soup.find_all(['node', 'way', 'relation']):
        t = tags_of(el)
        name = t.get('name', '') + ' ' + t.get('short_name', '')
        if not any(k.lower() in name.lower() for k in keywords):
            continue
        if 'route' in t or t.get('type') == 'route':  # пропускаем автобусные маршруты
            continue
        score = 3 if t.get('amenity') == 'university' else 2 if 'building' in t else 1
        if score > best_score:
            coords = center(el, nodes, ways)
            if coords:
                best, best_score = (t.get('name'), coords), score
    return best


def stops_of(filename):
    soup = load(filename)
    stops = {}
    for node in soup.find_all('node'):
        t = tags_of(node)
        if t.get('public_transport') == 'stop_position' or t.get('highway') == 'bus_stop':
            stops[t.get('name', 'id ' + node['id'])] = (float(node['lat']), float(node['lon']))
    return stops


# --- Расстояния между остановками (из карты ВВГУ) ---
stops = stops_of(FILES['ВВГУ'][0])
print('Расстояния между остановками:')
for (n1, p1), (n2, p2) in combinations(stops.items(), 2):
    print(f'  {n1} — {n2}: {haversine(p1, p2):.0f} м')

# --- Координаты вузов ---
print('\nКоординаты вузов:')
unis = {}
for short, (filename, keywords) in FILES.items():
    found = find_university(filename, keywords)
    if found:
        name, coords = found
        unis[short] = coords
        print(f'  {short} ({name}): lat={coords[0]:.7f}, lon={coords[1]:.7f}')
    else:
        print(f'  {short}: не найден в {filename}')

# --- Расстояния между вузами ---
print('\nРасстояния:')
for other in ('ТГМУ', 'ДВФУ'):
    if 'ВВГУ' in unis and other in unis:
        d = haversine(unis['ВВГУ'], unis[other])
        print(f'  ВВГУ — {other}: {d:.0f} м ({d / 1000:.2f} км)')
