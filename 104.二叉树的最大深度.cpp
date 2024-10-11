/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth_0(TreeNode *root)
    {
        // 仍然用递归
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    int maxDepth(TreeNode *root)
    {
        // 迭代
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            // 每一层的节点数
            int size = q.size();
            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
// @lc code=end
