class Solution {
public:
    int dp[13][10010];
    int coinChange(vector<int>& coins, int amount) {
      memset(dp, -1, sizeof dp);
      int res = solve(coins, 0, amount);
      return res == 100000000 ? -1 : res;
    }
    
    int solve(vector<int>& coins, int pos, int amount) {
        if(pos == coins.size()) {
            return amount == 0 ? 0 : 100000000;
        }
        if(dp[pos][amount] != -1)
            return dp[pos][amount];
        
        int q1 = solve(coins, pos + 1, amount);
        int q2 = 100000000;
        if(amount - coins[pos] >= 0){
            q2 = 1 + solve(coins, pos, amount - coins[pos]);
        }
        
        return dp[pos][amount] = min(q1, q2);
    }
    
};