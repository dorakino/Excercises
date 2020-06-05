#Kinorányi Dóra, shamir

import random

class Point:
    def __init__(self,i,a,b):
        self.i = i
        self.a = 0
        self.b = 0

class Shamir_div:
    S = 0
    n = 0
    k = 0
    myPrime = 0
    myListRandom = []
    myListPoints = []

    def __init__(self,S,n,k,myPrime):
        self.myListRandom = []
        self.myListPoints = []
        self.S = S
        self.n = n
        self.k = k
        self.myPrime = myPrime

    def division(self):
        for i in range(self.k):
            p = random.randint(1,21)*5
            q = random.randint(1,21)*7
            w = random.randint(1,21)*11
            self.myListRandom.append(((p+q+w)*13)%self.myPrime)

        for i in range(1, self.n+1):
            temp = self.S
            for j in range(1,self.k):
                temp = temp + i^j*self.myListRandom[j]
            self.myListPoints.append([i,temp])
        print("single points i give to participants:")
        for i in range(self.n):
            print(i+1,(self.myListPoints[i][1]))

class Shamir_rec:
    k=0
    pointList = []

    varList = []
    poliList = []
    tempVarList = []
    polynom = 0
    def __init__(self,k,pointList):
        self.k=k
        self.pointList = pointList
    def reconstruction(self):
        for i in range(self.k):
            self.tempVarList = []
            for j in range(self.k):
                if i==j:
                    self.tempVarList.append(1)
                    self.tempVarList.remove(1)
                else:
                    self.tempVarList.append(self.pointList[j])
            self.varList.append(self.tempVarList)

        for i in range(self.k):
            for j in range(self.k-1):
                self.poliList.append(1)
                temp = (0-(self.varList[i][j][0]))/((self.pointList[i][0])-(self.varList[i][j][0]))
                self.poliList[i] = self.poliList[i]*temp
        for i in range(self.k):
            self.polynom = self.polynom + self.pointList[i][1]*self.poliList[i]
        print("The secret is: ", self.polynom)

osztaly = Shamir_div(3144, 5, 4,57646075230343487)
osztaly.division()

a = Shamir_rec(2, [[1, 5341],[2, 7534],[4, 16508],[5, 19849]])
a.reconstruction()
