class Solution:
    def __init__(self):
        self.dp = [-1 for i in range(110)]
        
    def rob(self, nums: List[int]) -> int:
        self.nums = nums
        return self.solve(0)
    
    def solve(self, pos) -> int:
        if pos >= len(self.nums):
            return 0
        
        if self.dp[pos] != -1:
            return self.dp[pos]
        
        self.dp[pos] = max(self.nums[pos] + self.solve(pos + 2), self.solve(pos + 1))
        return self.dp[pos]