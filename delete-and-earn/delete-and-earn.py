class Solution:
    def __init__(self):
        self.dp = [ [-1 for i in range(3)] for j in range(10010)]
        self.freq = [ 0 for i in range(10010)]
        
    def deleteAndEarn(self, nums: List[int]) -> int:
        mx = 0
        for num in nums:
            self.freq[num] = self.freq[num] + 1
            mx = max(mx, num)
        return self.solve(mx, 0)
    
    def solve(self, num, action):
        if num == 0:
            return 0
        
        if num == 1:
            return self.freq[num] * num
        
        if self.dp[num][action] != -1:
            return self.dp[num][action]
        
        res1 = self.solve(num - 1, 0)
        res2 = (self.freq[num] * num) + self.solve(num - 2, 1)
        
        self.dp[num][action] = max(res1, res2)
        return self.dp[num][action]
            
        