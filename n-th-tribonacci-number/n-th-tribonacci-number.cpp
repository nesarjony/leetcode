class Solution {
public:
    int tribs[40];
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 1;
        
        if(tribs[n] > 0)
            return tribs[n];
        
        return tribs[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};