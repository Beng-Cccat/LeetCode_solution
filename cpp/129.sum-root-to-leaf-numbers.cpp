/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */

// @lc code=start
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
    int sumNumbers(TreeNode* root) {
        int res=0;

        function<void(TreeNode*,int)> sum=[&](TreeNode* t,int s){
            if(!t)
                return;
            
            if(!t->left&&!t->right){
                res+=s;
                return;
            }

            //穷举
            if(t->left){
                sum(t->left,s*10+t->left->val);
            }
            if(t->right)
                sum(t->right,s*10+t->right->val);
        };

        sum(root,root->val);
        return res;
    }
};
// @lc code=end

