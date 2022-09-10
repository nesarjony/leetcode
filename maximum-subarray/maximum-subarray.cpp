class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = (int)-1e5;
        int prev = 0;
        for(int i = 0; i < nums.size(); i++){
            if(prev + nums[i] <= nums[i]){
                prev = nums[i];
            }else{
                prev = prev + nums[i];
            }
            maxSum = max(maxSum, prev);
        }
        
        return maxSum;
    }
};