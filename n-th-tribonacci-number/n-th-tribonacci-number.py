class Solution:
    def __init__(self):
        self.dp = [ -1 for i in range(40)]
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        
        if self.dp[n] != -1:
            return self.dp[n]
        
        self.dp[n] = self.tribonacci(n - 3) + self.tribonacci(n-2) + self.tribonacci(n-1)
        return self.dp[n]