class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        prev = 0
        mx = -10000000
        for i in range(0, len(nums)):
            if nums[i] > (nums[i] + prev):
                prev = nums[i]
            else:
                prev = prev + nums[i]
            
            mx = max(mx, prev)
            
        return mx