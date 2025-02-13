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
private:
    void goodNodesUtil(TreeNode* root, int &ans, int maxTillNow){
        if(!root){
            return;
        }

        if(maxTillNow <= root->val){
            ans++;
            maxTillNow = root->val;
        }

        goodNodesUtil(root->left, ans, maxTillNow);
        goodNodesUtil(root->right, ans, maxTillNow);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans = 0;
        goodNodesUtil(root, ans, INT_MIN);
        return ans;
    }
};