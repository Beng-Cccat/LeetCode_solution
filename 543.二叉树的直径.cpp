/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree_0(TreeNode *root)
    {
        /*
        如果这个最长路径经过root，那么可以直接用左子树的深度+右子树的深度+2即可
        但是这里有个问题就是，这个最长路径不一定经过root，而有可能是左子树或者右子树中的某一个部分
        所以这里有两个变量，一个是深度，一个是最长路径
        但是递归只能返回一个值，所以这里肯定不是简单的递归，还需要一个标识最长路径的变量
        */
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return 0;
        int res = 0;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode *root, int &res)
    {
        if (root == nullptr)
            return 0;
        // 这里的res即当前最大路径，使用引用进行传递可以保证在递归过程中，res的值是最大的
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left + right);
        return max(left, right) + 1;
    }

        int ans = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        depth(root);
        // 这里为什么要减1呢，因为直径是指两个节点之间的边的数量，而不是节点的数量
        return ans - 1;
    }

    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        // 这里需要判断一下左右子树的直径
        int Lh = depth(root->left);
        int Rh = depth(root->right);
        ans = max(ans, Lh + Rh + 1);

        // 返回的是深度
        return max(Lh, Rh) + 1;
    }
};
// @lc code=end
