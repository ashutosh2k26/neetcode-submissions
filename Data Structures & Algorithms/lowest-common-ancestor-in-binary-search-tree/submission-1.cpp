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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       int pv = p->val;
       int qv = q->val;
       int rv = root->val;
       static TreeNode *common;

      
       if ( (pv <= rv && rv <= qv) || 
            (qv <= rv && rv <= pv) ||
            root == nullptr) {
            std::cout<<"here\n";
            std::cout<<"left "<<pv<<" right "<<qv<<" val "<<rv<<"\n";
            common = root;
            return root;
       } 

       if (pv <= rv && qv <= rv) {
          std::cout<<"left";
          std::cout<<"left "<<pv<<" right "<<qv<<" val "<<rv<<"\n";
          lowestCommonAncestor(root->left,p,q);
       } 

       if( qv > rv && pv > rv) {
         std::cout<<"right";
         std::cout<<"left "<<pv<<" right "<<qv<<" val "<<rv<<"\n";
         lowestCommonAncestor(root->right,p,q);
       }
       
       return common;
    }
};
