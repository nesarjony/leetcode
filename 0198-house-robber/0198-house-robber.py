class Solution:
    def __init__(self):
        self.dp = [-1 for i in range(110)]
        
    def rob(self, nums: List[int]) -> int:
        dp = [0, nums[0]]
        n = len(nums)
        for i in range(2, n + 1):
            dp.append(max(nums[i - 1] + dp[i-2], dp[i-1]))
        return dp[n]