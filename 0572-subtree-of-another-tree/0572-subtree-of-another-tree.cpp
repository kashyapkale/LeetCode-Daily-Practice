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
    bool checkTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL){
            return true;
        }

        if(root == NULL || subRoot == NULL){
            return false;
        }

        if(root->val == subRoot->val){
            return checkTree(root->left, subRoot->left) && checkTree(root->right, subRoot->right);
        }

        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root == NULL && subRoot == NULL){
            return true;
        }

        if(root == NULL || subRoot == NULL){
            return false;
        }
        
        if(root->val == subRoot->val && checkTree(root, subRoot)){
            return true;
        }

        bool right = isSubtree(root->right, subRoot);
        bool left = isSubtree(root->left, subRoot);
        return right || left;
    }
};