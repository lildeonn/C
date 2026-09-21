import networkx as nx
import matplotlib.pyplot as plt

G = nx.petersen_graph()

pos1 = {0: (90, 308), 6: (55, 260), 1: (121, 258), 4: (4, 233), 5: (150, 170),
        9: (88, 142), 8: (52, 72), 3: (0, 20), 2: (100, 5), 7: (168, 25)}
pos2 = {4: (62, 308), 3: (166, 265), 9: (121, 203), 0: (0, 172), 8: (135, 157),
        7: (130, 108), 5: (75, 77), 6: (108, 77), 2: (166, 32), 1: (62, 7)}

plt.subplot(121)
nx.draw(G, pos1, with_labels=True, font_weight='bold')
plt.subplot(122)
nx.draw(G, pos2, with_labels=True, font_weight='bold')
plt.show()
