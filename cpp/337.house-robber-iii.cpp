/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    int rob_fail(TreeNode* root) {
        int res=0;
        int even=0;
        int odd=0;

        queue<TreeNode*> q;
        q.push(root);

        bool tag=true;
        while(!q.empty()){
            int len=q.size();
            tag=!tag;
            for(int i=0;i<len;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(tag){
                    odd+=temp->val;
                }
                if(!tag){
                    even+=temp->val;
                }
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }

        res=max(even,odd);
        return res;
    }

    int rob(TreeNode* root) {
        function<pair<int,int>(TreeNode*)> dfs=[&](TreeNode* t){
            if(!t)return pair<int,int>{0,0};
            pair<int,int> left=dfs(t->left);
            pair<int,int> right=dfs(t->right);

            int rob_this=t->val+left.second+right.second;
            int not_rob_this=max(left.first,left.second)+max(right.first,right.second);

            return pair<int,int>{rob_this,not_rob_this};
        };

        auto res=dfs(root);
        return max(res.first,res.second);
    }
};
// @lc code=end

