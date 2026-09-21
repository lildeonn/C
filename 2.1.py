import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

n = int(input("Число вершин: "))
print("Вводи строки матрицы через пробел:")
P = [list(map(int, input().split())) for _ in range(n)]
G = nx.DiGraph(np.array(P))
nx.draw(G, with_labels=True, node_size=300, arrows=True)
plt.show()
