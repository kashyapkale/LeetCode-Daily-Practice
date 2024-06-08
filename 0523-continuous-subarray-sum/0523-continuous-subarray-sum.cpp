class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> index_map;
        int sum = 0;
        int N = nums.size();
        index_map[0] = -1;
        
        for (int i = 0; i < N; i++) {
            sum += nums[i];
            int mod_result = sum % k;
            
            if (mod_result < 0) mod_result += k;  // Handle negative remainders
            
            if (index_map.find(mod_result) != index_map.end()) {
                if (i - index_map[mod_result] > 1) {
                    return true;
                }
            } else {
                index_map[mod_result] = i;
            }
        }
        
        return false;
    }
};