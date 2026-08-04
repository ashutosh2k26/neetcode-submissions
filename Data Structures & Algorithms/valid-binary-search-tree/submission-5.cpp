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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        return dfs(root,INT_MIN,INT_MAX);
    
    }

    bool dfs(TreeNode* root,  int min, int max) {
        if(root == nullptr) {
            return true; 
        }
        
        if(root->val <= min || root->val >= max) {
            return false;
        }

        bool bleft = dfs(root->left,min,root->val);
        bool bright = dfs(root->right,root->val,max);
        return bleft && bright;
        
    }
};
