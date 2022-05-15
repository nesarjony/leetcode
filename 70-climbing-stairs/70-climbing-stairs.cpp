class Solution {
public:
    int dp[50];
    int climbStairs(int n) {
        for(int i = 0; i <= n; i++) {
            dp[i] = -1;
        }
        return solve(n);
    }
    
    int solve(int n) {
        if(n == 0)
            return 1;
        if(n < 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = solve(n-1) + solve(n-2);
    }
};