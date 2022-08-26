class Solution {
public:
    bool reorderedPowerOf2(int n) {
        for(int i = 1; i <= 1000000000; i *= 2) {
            if (isAchiveable(i, n)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool isAchiveable(int a, int b) {
        string aa = std::to_string(a);
        string bb = std::to_string(b);
        
        
        if (aa[0] == '0')
            return false;
        
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        
        return aa == bb;
    }
};