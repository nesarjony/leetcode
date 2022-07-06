class Solution {
public:
    map<int,int>freq;
    int dp[20010][3];
    int deleteAndEarn(vector<int>& nums) {
        int mx = 0;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            mx = max(mx, nums[i]);
        }
        
//         for(auto it: freq){
//             printf("%d %d\n", it.first, it.second);
//         }
        
        memset(dp, -1, sizeof dp);
        
        return solve(mx, 0);
    }
    
    int solve(int num, int action) {
        //printf("%d\n", num);
        if(num == 0) {
            return 0;
        }
        
        if(num == 1) {
            return freq[num] * num;
        }
        
        if(dp[num][action] != -1) {
            return dp[num][action];
        }
        
        int q1 = solve(num-1, 0);
        int q2 = (freq[num] * num) + solve(num-2, 1);
        
        return dp[num][action] = max(q1, q2);
    }
};