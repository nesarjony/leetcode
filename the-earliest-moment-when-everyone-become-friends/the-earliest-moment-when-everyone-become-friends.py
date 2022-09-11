from functools import cmp_to_key

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
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        def compare(a, b):
            return a[0] - b[0]
        
        logs.sort(key=cmp_to_key(compare))
        dsu = DSU(n + 5)
        history = set()
        for log in logs:
            u = log[1]
            v = log[2]
            
            if dsu.find(u) != dsu.find(v):
                dsu.union(u, v)
                history.add(u)
                history.add(v)
            
            mp = {}
            for i in range(0, n):
                mp[dsu.find(i)] = True
            
            if len(mp) == 1 and len(history) == n:
                return log[0]
            
        return -1
            
            
        