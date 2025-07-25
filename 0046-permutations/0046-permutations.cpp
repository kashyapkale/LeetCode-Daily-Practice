class Solution {
private:
    void permuteUtil(int MAX_SIZE, vector<int> &curr, vector<vector<int>> &ans, vector<int>& nums, unordered_map<int, bool> &vis) {
        if(curr.size() == MAX_SIZE){
            ans.push_back(curr);
        }

        for(int i = 0; i < MAX_SIZE; i++){
            if(!vis[i]){
                curr.push_back(nums[i]);
                vis[i] = true;
                permuteUtil(MAX_SIZE, curr, ans, nums, vis);
                curr.pop_back();
                vis[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_map<int, bool> umap;
        permuteUtil(nums.size(), curr, ans, nums, umap);
        return ans;
    }
};