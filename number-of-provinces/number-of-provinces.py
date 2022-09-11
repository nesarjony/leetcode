class DSU:
    def __init__(self, N):
        self.parent = [i for i in range(0, N)]
        self.ranks  = [0 for i in range(0, N)]
        
    def find(self, node):
        if node == self.parent[node]:
            return node
        #print(node)
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]
    
    def union(self, u, v):
        a = self.find(u)
        b = self.find(v)
        #print(a, b, u, v)
        
        if a != b:
            if self.ranks[a] < self.ranks[b]:
                temp = a
                a = b
                b = temp
            
            self.parent[b] = a
            
            if self.ranks[a] == self.ranks[b]:
                self.ranks[a] = self.ranks[a] + 1
    
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        dsu = DSU(len(isConnected) + 5)
        #print(dsu.parent)
        for i in range(len(isConnected)):
            for j in range(len(isConnected[i])):
                if isConnected[i][j]:
                    dsu.union(i + 1, j + 1)
        #print(dsu.parent)
        mp = {}
        for i in range(1, len(isConnected) + 1, 1):
            parent = dsu.find(i)
            #print(parent)
            mp[parent] = 1
        
        return len(mp)
        