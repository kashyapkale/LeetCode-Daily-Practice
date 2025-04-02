class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int len = nums.size();
        long long ans = INT_MIN;
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                for(int k = j + 1; k < len; k++){
                    long long curr_addition = (nums[i] - nums[j]);
                    long long curr_mul = nums[k];
                    long long curr_val = curr_addition * curr_mul;
                    ans = ans < curr_val ? curr_val : ans;
                }
            }
        }

        return ans < 0 ? 0 : ans;
    }
};