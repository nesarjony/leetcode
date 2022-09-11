class Solution:
    def __init__(self):
        self.dp = [-1 for i in range(1010)]
        
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        self.cost = cost
        return min(self.solve(0), self.solve(1))
    
    def solve(self, pos) -> int:
        if pos >= len(self.cost):
            return 0
        
        if self.dp[pos] != -1:
            return self.dp[pos]
        
        self.dp[pos] = self.cost[pos] + min(self.solve(pos + 1), self.solve(pos + 2))
        return self.dp[pos]
        