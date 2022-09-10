class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        low = 0
        high = len(nums) - 1
        res1 = -1
        
        while low <= high:
            mid = (low + high) // 2
            
            if target <= nums[mid]:
                high = mid - 1
                if target == nums[mid]:
                    res1 = mid
            else:
                low = mid + 1
                
        low = 0
        high = len(nums) - 1
        res2 = -1
        while low <= high:
            mid = (low + high) // 2
            if target >= nums[mid]:
                low = mid + 1
                if target == nums[mid]:
                    res2 = mid
            else:
                high = mid - 1
                
                
        return [res1, res2]