/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(root->val);

        function<void(TreeNode*,int)> dfs=[&](TreeNode* t,int sum){
            if(!t)
                return;
            
            if(!t->left&&!t->right&&sum==targetSum){
                res.push_back(path);
                return;
            }

            if(t->left){
                path.push_back(t->left->val);
                dfs(t->left,sum+t->left->val);
                path.pop_back();
            }
            if(t->right){
                path.push_back(t->right->val);
                dfs(t->right,sum+t->right->val);
                path.pop_back();
            }
        };

        int sum=root->val;
        dfs(root,sum);
        return res;
    }
};
// @lc code=end

