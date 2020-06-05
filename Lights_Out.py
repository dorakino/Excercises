import numpy as np
import sympy as sym
import math
import random as rn
import matplotlib.pyplot as plt
import csv
import networkx as nx
from datetime import datetime

class LightsOut:
    def __init__(self, problem):
        self.problem = problem
        self.n = len(problem[0])
        self.arr = np.zeros(self.n**2)
        s = (self.n**2,self.n**2 + 1)
        self.G = np.zeros(s)
        self.A = np.zeros((self.n**2,self.n**2))
        print(self.problem)
        
    def coord(self, a, b):
        return (self.n * a + b)
        
    def prepareRow(self, i, j):
        arr = np.zeros(self.n**2)
        #arr[self.coord(i,j)] = 1
        if i-1 >= 0:
            arr[self.coord(i-1,j)] = 1
        if i+1 <= self.n-1:
            arr[self.coord(i+1,j)] = 1
        if j-1 >= 0:
            arr[self.coord(i,j-1)] = 1
        if j+1 <= self.n-1:
            arr[self.coord(i,j+1)] = 1
        return arr

    def prepareMtx(self):
        mtx = []
        for i in range(self.n):
            for j in range((self.n)):
                mtx.append(self.prepareRow(i, j))
        self.A =  mtx
    
    def prepareArr(self):
        arr = np.zeros(self.n**2)
        for i in range(self.n):
            for j in range((self.n)):
                if self.problem[i][j] == 1:
                    arr[self.coord(i,j)] = 1
        self.arr = arr
    
    def prepareG(self):
        self.G[:,:self.n**2] = self.A
        self.G[:,self.n**2] = self.arr.T
            
    # matrix a. és b. sorat felcsereli
    def sorcsere(self, a, b):
        tmp = [i for i in self.G[a]]
        self.G[a] = self.G[b]
        self.G[b] = tmp

    # matrix a. sorabol kivonja a b. sort
    def sorkivonas(self, a, b):
        for i in range(len(self.G[a])):
            self.G[a][i] = (self.G[a][i] - self.G[b][i]) % 2
            
    def gausselim(self):
        x = []
        for j in range(len(self.G)):
            for i in range(j, len(self.G)):
                if self.G[i][j] == 1:
                    self.sorcsere(i, j)
                    break
            for i in range(len(self.G)):
                if i != j and self.G[i][j] == 1:
                    self.sorkivonas(i, j)
        for j in range(len(self.G)):
            x.append(self.G[j][self.n**2])
        self.x = x
        return True
        
    def switch(self, matrix, i, j):
        #matrix[i][j] = (matrix[i][j] +1 ) % 2
        if i-1 >= 0:
            matrix[i-1][j] = (matrix[i-1][j] +1 ) % 2
        if i+1 <= self.n-1:
            matrix[i+1][j] = (matrix[i+1][j] +1 ) % 2
        if j-1 >= 0:
            matrix[i][j-1] = (matrix[i][j-1] +1 ) % 2
        if j+1 <= self.n-1:
            matrix[i][j+1] = (matrix[i][j+1] +1 ) % 2
        return matrix
    
    def visualization(self):
        for ind, i in enumerate(self.problem):
            for y in range(len(i)):
                if self.x[self.coord(ind,y)] == 1:
                    print('a(z)', ind+1, '. sor', y+1, '. elemet valasztjuk:')
                    self.problem = self.switch(self.problem, ind, y)
                    print(self.problem)
        for row in self.problem:
            for element in row:
                if element != 0:
                    print("nincs megoldás")
                    return

    def algorithm(self):
        self.prepareMtx()
        self.prepareArr()
        self.prepareG()
        self.gausselim()       
        self.visualization()


#erre az esetre kiírja a megoldást:
#A = np.array([[0,  1,  0],[1,  1,  0],[0,  1,  1]])

#erre az esetre kiírja a megoldást:
A = np.array([[1,  1,  0,  1,  1],[1,  1,  0,  1,  1],[0,  1,  1,  1,  0],[1,  0,  0,  1,  0],[1,  1,  1,  1,  1]])

#erre az esetre nincs megoldás:
#A = np.array([[0,  1,  0,  0,  0],[1,  1,  0,  0,  1],[0,  1,  1,  1,  0],[1,  0,  0,  1,  0],[1,  0,  0,  0,  1]])

feladat = LightsOut(A)
feladat.algorithm()
