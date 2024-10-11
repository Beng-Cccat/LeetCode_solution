/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric_0(TreeNode *root)
    {
        // 使用队列，迭代
        queue<TreeNode *> q;
        q.push(root);

        vector<int> level;
        while (!q.empty())
        {
            int size = q.size();
            level.clear();
            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node == nullptr)
                {
                    // 用-101表示空节点，因为题目中说节点值为-100-100，所以不会有-101
                    level.push_back(-101);
                }
                else
                {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            // 判断level中的值是否对称
            for (int i = 0; i < level.size() / 2; i++)
            {
                if (level[i] != level[level.size() - 1 - i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isSymmetric(TreeNode *root)
    {
        // 使用递归
        if (root == nullptr)
            return true;
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        // 这个判断条件可以直接写成(!left||!right)
        if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr))
            return false;
        if (left->val != right->val)
            return false;
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
// @lc code=end
