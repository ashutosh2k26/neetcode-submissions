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
    int goodNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int mX = root->val;
        goodN = 0;
        GoodNodes(root,mX);
        return goodN;

    }
    void  GoodNodes(TreeNode *root, int mX) {
        if(root == nullptr) {
            return;
        }

        if(root->val >= mX) {
            mX = root->val;
            goodN += 1;
        }

        GoodNodes(root->left,mX);
        GoodNodes(root->right,mX);
    }

    int goodN;
};
