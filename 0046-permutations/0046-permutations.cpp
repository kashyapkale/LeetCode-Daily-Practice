/*
Approach - 1 (Extra Space)
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
*/


class Solution {
private:
    void permuteUtil(int index, int MAX_SIZE, vector<vector<int>> &ans, vector<int>& nums) {
        if(index == MAX_SIZE){
            ans.push_back(nums);
        }

        for(int i = index; i < MAX_SIZE; i++){
            swap(nums[index], nums[i]);
            permuteUtil(index+1, MAX_SIZE, ans, nums);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteUtil(0, nums.size(), ans, nums);
        return ans;
    }
};