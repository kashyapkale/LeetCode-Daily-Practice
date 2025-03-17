class Solution {
public:
    /*int jump(vector<int>& nums) {
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
            cout<<dp[i]<<endl;
        }

        return dp[0];
    }*/

int jump(vector<int>& nums){
    
    int size = nums.size();
    
    if(size == 0) {
        return -1;
    }
    
    if(size == 1) {
        return 0;
    }
    
    int farthest_element = 0;
    int current_end = 0;
    int jump = 0;
    
    for(int i = 0; i < size - 1; i++) {
        farthest_element = max(farthest_element, i + nums[i]);
        
        if(i == current_end) {
            jump++;
            current_end = farthest_element;
            if(current_end >= size-1) break;
        }
        
    }
    
    return jump;
    
}
};


