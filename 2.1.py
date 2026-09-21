import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

P0 = [[0,1,1,1,0],
      [1,0,1,1,0],
      [1,1,0,1,0],
      [0,1,0,0,0],
      [1,1,1,1,0]]
G = nx.DiGraph(np.array(P0))

pos = {3: (405, 304), 1: (94, 194), 2: (1, 67), 4: (349, 60), 0: (198, 1)}
nx.draw(G, pos, with_labels=True, node_size=300, arrows=True)
plt.show()
