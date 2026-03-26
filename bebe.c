# Универсум - компьютерные игры (для примера возьмем 10 игр)
# Индексы игр: 0-9

# Определяем множества (для примера)
# A - стрелялки (шутеры)
A_bin = [1, 1, 0, 0, 1, 0, 0, 0, 1, 0]  # игры: 0,1,4,8 - стрелялки

# B - бродялки (квесты, RPG)
B_bin = [0, 1, 1, 1, 0, 0, 1, 0, 0, 0]  # игры: 1,2,3,6 - бродялки

# C - стратегии
C_bin = [0, 0, 0, 1, 0, 1, 1, 1, 0, 0]  # игры: 3,5,6,7 - стратегии

# D - игры, которые можно пройти за один вечер
D_bin = [1, 1, 1, 0, 1, 0, 0, 0, 0, 1]  # игры: 0,1,2,4,9 - за один вечер

# not D - игры, которые нужно проходить долго (остальные)
# (вычисляется автоматически)

# E - игры, установленные на компьютере
E_bin = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]  # для примера - все игры установлены

# Преобразование двоичного вектора в список
def bin_to_list(M_bin):
    return [i for i in range(10) if M_bin[i]]

# Преобразование списка в двоичный вектор
def list_to_bin(M_list):
    M_bin = [0] * 10
    for elem in M_list:
        if 0 <= elem <= 9:
            M_bin[elem] = 1
    return M_bin

# Операции над множествами в двоичном представлении
def union(A, B):
    return [A[i] or B[i] for i in range(10)]

def intersection(A, B):
    return [A[i] and B[i] for i in range(10)]

def difference(A, B):
    return [A[i] and not B[i] for i in range(10)]

def complement(A):
    return [not A[i] for i in range(10)]

# Задание 5
print("=" * 60)
print("Задание 5. Компьютерные игры")
print("=" * 60)

# Выводим все множества
print("\nМножества:")
print(f"Универсум (все игры): {list(range(10))}")
print(f"A (стрелялки): {bin_to_list(A_bin)}")
print(f"B (бродялки): {bin_to_list(B_bin)}")
print(f"C (стратегии): {bin_to_list(C_bin)}")
print(f"D (за один вечер): {bin_to_list(D_bin)}")
print(f"not D (долгие игры): {bin_to_list(complement(D_bin))}")
print(f"E (установленные игры): {bin_to_list(E_bin)}")

# Первый студент: хочет пройти за один вечер стрелялку
# P1 = A ∩ D
P1 = intersection(A_bin, D_bin)
print(f"\nПервый студент (стрелялка за один вечер):")
print(f"P1 = A ∩ D = {bin_to_list(P1)}")

# Второй студент: хочет бродялку ИЛИ стратегию, которую нужно проходить долго
# P2 = B ∪ (C ∩ not D)
not_D = complement(D_bin)
C_and_not_D = intersection(C_bin, not_D)
P2 = union(B_bin, C_and_not_D)
print(f"\nВторой студент (бродялка или долгая стратегия):")
print(f"C ∩ not D = {bin_to_list(C_and_not_D)}")
print(f"P2 = B ∪ (C ∩ not D) = {bin_to_list(P2)}")

# Игра, подходящая обоим студентам
# P = P1 ∩ P2
P = intersection(P1, P2)
print(f"\nИгры, подходящие обоим студентам (без учета E):")
print(f"P = P1 ∩ P2 = {bin_to_list(P)}")

# С учетом установленных игр E
# Возможности = E ∩ P
possibilities = intersection(E_bin, P)
print(f"\nВозможности для игры сегодня (с учетом E):")
print(f"E ∩ P = {bin_to_list(possibilities)}")

if sum(possibilities) == 0:
    print("Нет подходящих игр для совместной игры!")
else:
    print(f"Студенты могут сыграть в игры: {bin_to_list(possibilities)}")

# Дополнительный анализ: что получилось?
print("\n" + "=" * 60)
print("Анализ результата:")
print("=" * 60)
print("P = A ∩ B ∩ D")
print(f"A ∩ B = {bin_to_list(intersection(A_bin, B_bin))}")
print(f"(A ∩ B) ∩ D = {bin_to_list(intersection(intersection(A_bin, B_bin), D_bin))}")
print(f"\nИтоговая формула: E ∩ A ∩ B ∩ D = {bin_to_list(possibilities)}")