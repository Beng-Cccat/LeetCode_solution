/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        //入队顺序不能变
        //变化的是每次得到的元素的序号
        //因此会用上[]
        //故在初始化的时候必须带上个数，不然会报错
        //即vector<int> temp(len)
        bool tag=true;//tag=false表示从右往左，tag=true表示从左往右
        while(!q.empty()){
            int len=q.size();
            vector<int> temp(len);
            for(int i=0;i<len;i++){
                TreeNode* t=q.front();
                q.pop();

                int index=tag?i:len-1-i;
                temp[index]=t->val;
                
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            tag=!tag;
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

