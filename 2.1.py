from math import radians, sin, cos, asin, sqrt
from itertools import combinations
from bs4 import BeautifulSoup

xml = open('map.xml', 'r', encoding='utf8').read()
soup = BeautifulSoup(xml, 'xml')  # XML-парсер из пакета lxml


def tags_of(node):
    return {t['k']: t['v'] for t in node.find_all('tag')}


def haversine(lat1, lon1, lat2, lon2):
    """Расстояние между двумя точками на сфере Земли, в метрах."""
    R = 6371000
    lat1, lon1, lat2, lon2 = map(radians, (lat1, lon1, lat2, lon2))
    a = sin((lat2 - lat1) / 2) ** 2 + cos(lat1) * cos(lat2) * sin((lon2 - lon1) / 2) ** 2
    return 2 * R * asin(sqrt(a))


# --- п.4-7: остановки ---
stops = {}
for node in soup.find_all('node'):
    t = tags_of(node)
    if t.get('public_transport') == 'stop_position' or t.get('highway') == 'bus_stop':
        stops[t.get('name', f"id {node['id']}")] = (float(node['lat']), float(node['lon']))

print('Остановки:')
for name, (lat, lon) in stops.items():
    print(f'  {name}: lat={lat}, lon={lon}')
print('Всего остановок:', len(stops))

# В OSM остановка «ВГУЭС» переименована во «Владивостокский Государственный Университет»
vvsu_name = next(n for n in stops if 'ВГУЭС' in n or 'Владивостокский Государственный' in n)
vvsu = stops[vvsu_name]
print(f'\nВГУЭС ({vvsu_name}): {vvsu}')
print('Некрасовская, 50:', stops['Некрасовская, 50'])

# --- п.8: суши-бары ---
sushi = 0
for node in soup.find_all(['node', 'way']):
    t = tags_of(node)
    if 'sushi' in t.get('cuisine', '').lower() or 'суши' in t.get('name', '').lower():
        sushi += 1
print('\nСуши-баров:', sushi)

# --- п.9: расстояния ---
print('\nРасстояния между остановками:')
for (n1, p1), (n2, p2) in combinations(stops.items(), 2):
    print(f'  {n1} — {n2}: {haversine(*p1, *p2):.0f} м')

# ТГМУ и ДВФУ в выгрузку не попадают, координаты взяты с карты
tgmu = (43.12917, 131.90222)   # ТГМУ, пр. Острякова, 2
dvfu = (43.02470, 131.89380)   # ДВФУ, о. Русский, п. Аякс, 10 (корпус A)

print(f'\nВГУЭС — ТГМУ: {haversine(*vvsu, *tgmu):.0f} м')
print(f'ВГУЭС — ДВФУ: {haversine(*vvsu, *dvfu) / 1000:.2f} км')

