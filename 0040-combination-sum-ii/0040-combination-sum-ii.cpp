class Solution {
private:
    void combinationSumUtil(int index, int target, vector<int> &temp, vector<vector<int>> &ans, vector<int>& candidates){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        int len = candidates.size();
        for(int i = index; i < len; i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }

            temp.push_back(candidates[i]);
            if(target - candidates[i] >= 0){
                combinationSumUtil(i+1, target - candidates[i], temp, ans, candidates);
            }
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSumUtil(0, target, temp, ans, candidates);
        return ans;
    }
};