class Solution {
public:
    int dp[105];
    int rob(vector<int>& nums) {
        for(int i = 0; i < 102; i++) {
            dp[i] = -1;
        }
        return solve(nums, 0);
    }
    
    int solve(vector<int>& nums, int pos)
    {
        if (pos >= nums.size()) {
            return 0;
        }
        
        if(dp[pos] != -1)
            return dp[pos];
        
     
        int q1 = solve(nums, pos + 1);
        int q2 = nums[pos] + solve(nums, pos + 2);
        
        return dp[pos] = max(q1, q2);
    }
};