class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        bool dp[len+5][len+5];
        memset(dp, false, sizeof dp);
        
        for(int i = 0; i < len; i++)
            dp[i][i] = true;
        int start = 0;
        int maxLen = 1;
        for (int i = 0; i < len - 1; i++) {
            dp[i][i+1] = (s[i] == s[i+1]);
            
            if (dp[i][i+1]) {
                start = i;
                maxLen = 2;
            }
        }
        
        for (int i = 3; i <= len; i++) {
            for (int j = 0; j <= len - i; j++) {
                int lst = j + i - 1;
                if (dp[j + 1][lst-1] && s[j] == s[lst]) {
                    dp[j][lst] = true;
                    if (i > maxLen) {
                        maxLen = i;
                        start = j;
                    }
                }
            }
        }
        //cout << start << " " << maxLen << endl;
        string res = "";
        
        for (int i = 0; i < maxLen; i++) {
            res += s[i + start];
        }
        return res;
    }
};