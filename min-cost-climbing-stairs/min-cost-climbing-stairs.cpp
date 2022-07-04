class Solution {
public:
    int dp[1005];
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i = 0; i < 1005; i++)
            dp[i] = -1;
        
        return min(solve(cost, 0), solve(cost, 1));
    }
    
    int solve(vector<int>&cost, int pos)
    {
        if(pos >= cost.size()){
            return 0;
        }
        
        if(dp[pos] != -1) {
            return dp[pos];
        }
        
        int q1 = cost[pos] + solve(cost, pos + 1);
        int q2 = cost[pos] + solve(cost, pos + 2);
        
        return dp[pos] = min(q1, q2);
    }
};