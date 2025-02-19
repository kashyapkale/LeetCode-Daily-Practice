class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len);
        dp[len - 1] = 0;
        if(len > 1)
            dp[len - 2] = 1;
        for(int i = len - 3; i >= 0; i--){
            int limit = nums[i];
            int min_step = INT_MAX;
            for(int j = i + 1; j <= i + limit && j < len; j++){
                min_step = min(min_step, dp[j]);
            }
            if(min_step != INT_MAX){
               dp[i] = min_step + 1; 
            } else {
                dp[i] = INT_MAX;
            }
        }

        return dp[0];
    }
};
