import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

P0 = [[0,1,1,1,0,1],
      [1,0,1,1,0,1],
      [1,1,0,1,0,1],
      [0,1,0,0,0,0],
      [1,1,1,1,0,1],
      [1,1,1,1,1,0]]
G = nx.DiGraph(np.array(P0))

pos = {2: (177, 290), 4: (0, 237), 1: (342, 233), 5: (204, 115), 0: (65, 57), 3: (380, 2)}
nx.draw(G, pos, with_labels=True, node_size=300, arrows=True)
plt.show()

