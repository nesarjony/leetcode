class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [ [-1 for i in range(1010)] for j in range(1010)]
        def solve(l, r):
            if l < 0 or r < 0:
                return 0
            
            if dp[l][r] != -1:
                return dp[l][r]
            
            m1 = 0
            m2 = 0
            
            
            if text1[l] == text2[r]:
                #print(l, r)
                m1 = 1 + solve(l-1, r-1)
            else:
                m2 = max(solve(l-1, r), solve(l, r-1))
            
            #print(text1, text2, l, r, m1, m2)
            
            dp[l][r] = max(m1, m2)
            
            return dp[l][r]
        
        return solve(len(text1)-1, len(text2) - 1)