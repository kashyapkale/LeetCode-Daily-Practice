class Solution {
private:
    static bool pair_comparator(pair<int, int> &A, pair<int, int> &B){
        if(A.second == B.second){
            return A.first > B.first;
        }

        return A.second > B.second;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n - k + 1; i++){
            unordered_map<int, int> freq_map;
            for(int j = i; j < n && j < i + k; j++){
                freq_map[nums[j]]++;
            }

            vector<pair<int, int>> sorted_curr;
            for(auto &p : freq_map){
                sorted_curr.push_back(p);
            }

            sort(sorted_curr.begin(), sorted_curr.end(), pair_comparator);

            int index = 0;
            int ans_sum = 0;
            while(index < sorted_curr.size() && index < x){
                ans_sum += (sorted_curr[index].first * sorted_curr[index].second);

                index++;
            }

            ans.push_back(ans_sum);
        }

        return ans;
    }
};