class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currSum = nums[0];
        int len = nums.size();
        int maxSum = currSum;
        for(int i = 1; i < len; i++){
            if(nums[i] <= nums[i-1]){
                maxSum = max(currSum, maxSum);
                currSum = nums[i];
            } else{
                currSum += nums[i];
            }
        }

        return max(currSum, maxSum);
    }
};