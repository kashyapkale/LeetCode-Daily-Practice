class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int len = nums.size();
        int positive = 0;
        int negative = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] < 0) {
                negative++;
            } else if(nums[i] > 0) {
                return max(negative, len - i);
            }
        }

        return max(negative, positive);
    }
};