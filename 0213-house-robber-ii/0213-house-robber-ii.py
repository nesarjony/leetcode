class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        return max(self.solve(nums[0:len(nums)-1]), self.solve(nums[1: len(nums)]))
    
    def solve(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        dp = [0, nums[0]]
        n = len(nums)
        
        for i in range(2, n + 1):
            dp.append(max(nums[i-1] + dp[i-2], dp[i-1]))
        
        print(dp)
        return dp[n]
    