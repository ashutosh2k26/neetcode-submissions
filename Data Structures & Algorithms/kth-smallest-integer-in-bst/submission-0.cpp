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
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) {
            return -1;
        }
        inorder(root);

        if(k-1 > inod.size()) {
            return -1;
        }

        return inod[k-1];
        
        
    }
    void inorder(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        inorder(root->left);
        inod.push_back(root->val);
        inorder(root->right);

    }
    vector<int> inod;;
};
