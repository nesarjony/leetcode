class Solution:
    def reverse(self, x: int) -> int:
        lower_bound = -2147483648
        upper_bound = 2147483648
        
        is_negative = False
        if x < 0:
            is_negative = True
            x = -1 * x
        res = 0
        
        while x > 0 :
            res = res * 10
            res = res + (x % 10)
            x = x // 10
        
        if is_negative:
            res = -1 * res
        
        if res < lower_bound or res > upper_bound:
            return 0
        return res