/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // 先沿着右上到左下的对角线翻转
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        // 再沿着中间横线翻转
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n / 2; i++)
            {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
    }
};
// @lc code=end
