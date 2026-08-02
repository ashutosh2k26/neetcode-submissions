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
        std::queue<TreeNode*> que;
        if(root == nullptr) {
            return vector<int>{};
        }
        vector<int> vec;
        que.push(root);
        vec.push_back(root->val);
        int level = 1;
        while(!que.empty()) {
            TreeNode* right = nullptr;
            int ele = 0;
            for(int i = 0 ; i < level && !que.empty() ; i++) {
                TreeNode *curr = que.front();
                que.pop();
                std::cout<<"level "<<level<<" curr-"<<curr->val<<"\n";
                
                if(curr->left != nullptr) {
                    std::cout<<"left "<<curr->left->val<<"\n";
                    que.push(curr->left);
                    right = curr->left;
                    ele++;
                }
                if(curr->right != nullptr) {
                    std::cout<<"right "<<curr->right->val<<"\n";
                    que.push(curr->right);
                    right = curr->right;
                    ele++;
                }
            }
            if(right != nullptr) {
                vec.push_back(right->val);
            }
            level *= 2;
            level = min(level,ele);  
        }
        return vec;
        
    }
};
