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
   
    int diameterOfBinaryTree(TreeNode* root) {
        mx = 0;
        dia(root);
        return mx -1 ;
    }

    int dia(TreeNode *root){
        if(root == nullptr) {
            return 0;
        }

        int l = dia(root->left);
        int r = dia(root->right);
        cout<<"root "<<root->val<<"\n";
        cout<<"l "<<l<<" r "<<r<<"\n";

        int mxl = max(l,r);
        mx = max(mx,l + r + 1);
        cout<<"mxl "<<mxl<<" mx "<<mx<<"\n";
        return mxl+1; 
    }

    int mx;
};
