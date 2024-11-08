class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set(nums.begin(), nums.end());
        
        int longest_streak = 0;
        for(int i : hash_set){
            if(!hash_set.count(i-1)){
                int curr_element = i;
                int current_streak = 0;
                while(hash_set.count(curr_element)){
                    curr_element++;
                    current_streak++;
                }
                longest_streak = max(current_streak, longest_streak);
            }
        }

        return longest_streak;
    }
};