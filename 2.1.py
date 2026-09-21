import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

names = ['A', 'B', 'C', 'D']

# 2. Матрица смежности
A = np.array([[0,1,0,1],
              [1,0,1,1],
              [0,1,0,1],
              [1,1,1,0]])

# 1. Рисуем граф
G = nx.relabel_nodes(nx.Graph(A), dict(enumerate(names)))
pos = {'A': (2, 1), 'B': (1, 2), 'C': (0, 1), 'D': (1, 0)}
nx.draw(G, pos, with_labels=True, node_color='red', node_size=700)
plt.show()

# 3. Матрица инцидентности
edges = [(i, j) for i in range(4) for j in range(i+1, 4) if A[i][j]]
I = np.zeros((4, len(edges)), dtype=int)
for k, (i, j) in enumerate(edges):
    I[i][k] = 1
    I[j][k] = 1
for k, (i, j) in enumerate(edges):
    print(f'e{k+1} = {names[i]}{names[j]}')
print('Матрица инцидентности:\n', I)

# 4. Матрица Кирхгофа (через ориентированную инцидентность)
O = I.copy()
for k, (i, j) in enumerate(edges):
    O[j][k] = -1
K = O @ O.T
print('Матрица Кирхгофа:\n', K)

# 5. Эксцентриситет и радиус
print('Эксцентриситеты:', nx.eccentricity(G))
print('Радиус:', nx.radius(G))
