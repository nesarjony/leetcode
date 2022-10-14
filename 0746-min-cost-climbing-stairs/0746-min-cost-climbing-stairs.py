class Solution:
    def __init__(self):
        self.dp = [-1 for i in range(1010)]
        
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost.append(0)
        n = len(cost)
        dp = [cost[0], cost[1]]
        for i in range(2, n ):
            dp.append(cost[i] + min(dp[i-1], dp[i-2]))
        return dp[n-1]
    