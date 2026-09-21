import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

# 2. Ввод матрицы смежности
n = int(input("Число вершин: "))
print("Вводи строки матрицы через пробел:")
A = np.array([list(map(int, input().split())) for _ in range(n)])
names = 'ABCDEFGHIJ'[:n]

# 1. Граф
G = nx.relabel_nodes(nx.Graph(A), dict(enumerate(names)))

# 3. Матрица инцидентности
edges = [(i, j) for i in range(n) for j in range(i+1, n) if A[i][j]]
I = np.zeros((n, len(edges)), dtype=int)
for k, (i, j) in enumerate(edges):
    I[i][k] = 1
    I[j][k] = 1
for k, (i, j) in enumerate(edges):
    print(f'e{k+1} = {names[i]}{names[j]}')
print('Матрица инцидентности:\n', I)

# 4. Матрица Кирхгофа
O = I.copy()
for k, (i, j) in enumerate(edges):
    O[j][k] = -1
print('Матрица Кирхгофа:\n', O @ O.T)

# 5. Эксцентриситет и радиус
print('Эксцентриситеты:', nx.eccentricity(G))
print('Радиус:', nx.radius(G))

nx.draw(G, nx.circular_layout(G), with_labels=True, node_color='red', node_size=700)
plt.show()
