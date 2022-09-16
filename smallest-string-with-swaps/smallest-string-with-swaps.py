class DSU:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0 for i in range(n)]
    
    def find(self, node):
        if self.parent[node] == node:
            return node
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]
    
    def union(self, u, v):
        a = self.find(u)
        b = self.find(v)
        
        
        if a != b:
            if self.rank[a] < self.rank[b]:
                swap(a, b)
            self.parent[b] = a
            
            if self.rank[a] != self.rank[b]:
                self.rank[b] = self.rank[b] + 1
        
        
class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        dsu = DSU(len(s))

        for pair in pairs:
            dsu.union(pair[0], pair[1])
        
        mp = {}
        
        for i in range(len(s)):
            parent = dsu.find(i)
            if not parent in mp:
                mp[parent] = []
            
            mp[parent].append(s[i])
        
        last_used = {}
        for m in mp:
            mp[m] = sorted(mp[m])
            last_used[m] = -1
        
        res = ""
        for i in range(len(s)):
            parent = dsu.find(i)
            if last_used[parent] + 1 >= len(mp[parent]):
                continue
            res = res + mp[parent][last_used[parent] + 1]
            last_used[parent] = last_used[parent] + 1
            
        return res
            
        