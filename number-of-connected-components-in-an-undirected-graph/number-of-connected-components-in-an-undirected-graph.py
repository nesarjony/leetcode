class DSU:
    def __init__(self, N):
        self.parent = [i for i in range(0, N)]
        self.ranks  = [0 for i in range(0, N)]
        
    def find(self, node):
        if node == self.parent[node]:
            return node
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]
    
    def union(self, u, v):
        a = self.find(u)
        b = self.find(v)
        
        if a != b:
            if self.ranks[a] < self.ranks[b]:
                temp = a
                a = b
                b = temp
            
            self.parent[b] = a
            
            if self.ranks[a] == self.ranks[b]:
                self.ranks[a] = self.ranks[a] + 1
                
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = DSU(n+5)
        
        for edge in edges:
            u = edge[0]
            v = edge[1]
            dsu.union(u, v)
        
        mp = {}
        
        for i in range(0, n, 1):
            parent = dsu.find(i)
            mp[parent] = 1
            
        return len(mp)
        