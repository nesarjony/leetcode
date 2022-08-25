class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>mp1, mp2;
        for(char ch: magazine) {
            mp1[ch]++;
        }
        
        for(char ch: ransomNote) {
            mp2[ch]++;
        }
        
        for(auto pair: mp2) {
            //cout << pair.first << " " << mp1[pair.first] << " " << pair.second << endl;
            if (mp1[pair.first] < pair.second) {
                return false;
            }
        }
        
        return true;
    }
};