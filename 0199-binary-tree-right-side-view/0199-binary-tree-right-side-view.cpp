/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };  
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }

        queue<pair<TreeNode*, int>> levelQueue;
        levelQueue.push(make_pair(root, 0));
        TreeNode* temp = NULL;
        levelQueue.push(make_pair(temp, -1));

        while(!levelQueue.empty()){
            TreeNode* topNode = levelQueue.front().first;
            int currentLevel = levelQueue.front().second;
            levelQueue.pop();
            if(!levelQueue.empty() && !topNode){
                levelQueue.push(make_pair(temp, -1));                
            }

            if(topNode && ((!levelQueue.empty() && !levelQueue.front().first) || levelQueue.empty())){
                ans.push_back(topNode->val);
            }

            if(topNode && topNode->left)
                levelQueue.push(make_pair(topNode->left, currentLevel+1));

            if(topNode && topNode->right)
                levelQueue.push(make_pair(topNode->right, currentLevel+1));
        }

        return ans;      
    }
};