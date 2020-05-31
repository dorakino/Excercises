import numpy as np
import sympy as sym
import math
import random as rn
import matplotlib.pyplot as plt
import csv
import networkx as nx
from datetime import datetime

class Prim:
    def __init__(self, G):
        self.G = G

    #prim fv lefuttatja a Prim algoritmust(, és visszatér a min. feszítőfával)
    def prim(self):
        
        Tree = nx.Graph()
        self.Tree = Tree
        
        #s lesz a kezdésnél kiválasztott tetsz. csúcs
        s = list(self.G.nodes())[0]
        Tree.add_node(s)
        
        # W tartalmazza a még feldolgozandó csúcsokat
        W = set(self.G.nodes()) - set(Tree.nodes())
        tmp = 0
        
        while W != set():
            if tmp != 0:
                s = s = list(W)[0]
            tmp += 1
            min_value = 1000000000
            min_arg_from = s
            min_arg_to = s
            
            for n in list(Tree.nodes()):
                for w in list(W):
                    
                    if self.G.has_edge(n,w):
                        
                        for a in list(set(Tree.nodes()) - set([n])):
                            if Tree.has_edge(a,w):
                                break

                        if self.G.get_edge_data(n,w)['weight'] < min_value:
                            min_value = self.G.get_edge_data(n,w)['weight']
                            min_arg_from = n
                            min_arg_to = w    
            Tree.add_node(min_arg_to)
            Tree.add_edge(min_arg_from,min_arg_to,weight=min_value)
            
            W -= set( [min_arg_to] )
        
        self.Tree = Tree
        #return Tree
        
    def abrazolas(self):

        edge_weight = nx.get_edge_attributes(G,'weight')
        
        red_edges = list(self.Tree.edges())
        edge_col = []
        for edge in G.edges():
            if edge in list(self.Tree.edges()) or edge[::-1] in list(self.Tree.edges()):
                edge_col.append('red')
            else:
                edge_col.append('black')

        node_pos = nx.spring_layout(G)
        nx.draw_networkx(G, node_pos,node_color= 'red', node_size=450)
        nx.draw_networkx_edges(G, node_pos,edge_color= edge_col, width=4)
        nx.draw_networkx_edge_labels(G, node_pos,edge_color= edge_col, edge_labels=edge_weight)
        
        plt.axis('off')
        plt.show()
        
        
# Pelda1:
G = nx.Graph()

G.add_node(1)
G.add_node(2)
G.add_node(3)
G.add_node(4)
G.add_node(5)
G.add_node(6)
G.add_node(7)

G.add_edge(1, 2, weight=2)
G.add_edge(2, 3, weight=6)
G.add_edge(2, 6, weight=2)
G.add_edge(3, 6, weight=3)
G.add_edge(3, 4, weight=5)
G.add_edge(3, 5, weight=4)
G.add_edge(4, 5, weight=3)
G.add_edge(1, 7, weight=1)
G.add_edge(5, 7, weight=9)
G.add_edge(1, 6, weight=8)
G.add_edge(5, 6, weight=1)

p = Prim(G)
p.prim()
p.abrazolas()


# Pelda2:
G = nx.Graph()

G.add_edge('a', 'b', weight=0.6)
G.add_edge('a', 'c', weight=0.2)
G.add_edge('c', 'd', weight=0.1)
G.add_edge('c', 'e', weight=0.7)
G.add_edge('c', 'f', weight=0.9)
G.add_edge('a', 'd', weight=0.3)
g = Prim(G)
g.prim()
g.abrazolas()
