class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int dp[300][12];
        
        memset(dp, -1, sizeof dp);
        
        if (jobDifficulty.size() < d)
            return -1;
        
        return solve(0, 1, jobDifficulty, d, dp);
    }
    
    int solve(int pos, int day, vector<int>& difficulty, int d, int dp[300][12]) {
        if (day > d) {
            return 0;
        }
        
        if (dp[pos][day] != -1) {
            return dp[pos][day];
        }
        
        if (day == d) {
            int mx = 0;
            for(int i = pos; i < difficulty.size(); i++) {
                mx = max(mx, difficulty[i]);
            }
            return mx;
        }
        
        int hardest = difficulty[pos];
        int limit = difficulty.size() - (d - day);
        int res = 1000000;
        for(int i = pos; i < limit ; i++) {
            hardest = max(hardest, difficulty[i]);
            res = min(res, hardest + solve(i + 1, day + 1, difficulty, d, dp));
        }
        
        return dp[pos][day] = res;
    }
};