/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        // 递归
        vector<int> res;
        inorder(root, res);
        return res;
    }

    // 这里传递的res必须是引用
    void inorder(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left != nullptr)
        {
            inorder(root->left, res);
        }
        res.push_back(root->val);
        if (root->right != nullptr)
        {
            inorder(root->right, res);
        }
    }
};
// @lc code=end
