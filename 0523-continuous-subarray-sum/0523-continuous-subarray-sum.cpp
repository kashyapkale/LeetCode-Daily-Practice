class Solution {
  public: 
  bool checkSubarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> index_map;
    int sum = 0;
    int N = nums.size();
    sum = 0;
    index_map[0] = -1;
    for (int i = 0; i < N; i++) {
      sum = sum + nums[i];
      int mod_result = sum % k;
      if(index_map.find(mod_result) != index_map.end()) {
            if(i - index_map[mod_result] > 1){
                return true;
            }
                
      } else {
            index_map[mod_result] = i;
        }
    }

    return false;
  }

};