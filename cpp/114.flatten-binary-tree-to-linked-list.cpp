/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if(!root)return;
        //先把左右变的扁平
        flatten(root->left);
        flatten(root->right);
        //然后标记左右子树，这一次该换了
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        //右子树变成左子树，左子树为null
        root->right=left;
        root->left=NULL;
        //找到原本的右子树改在的位置，然后接上
        TreeNode* ptr=root;
        while(ptr->right)ptr=ptr->right;
        ptr->right=right;
    }
};
// @lc code=end

