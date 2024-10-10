/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // 找到一个基准点：右上角或者左下角
        /*
        若是右上角，若target>matrix[i][j]，则i++，若target<matrix[i][j]，则j--
        若是左下角，若target>matrix[i][j]，则j++，若target<matrix[i][j]，则i--
        */

        // 以左下角为例
        int i = matrix.size() - 1;
        int j = 0;
        while (i >= 0 && j < matrix[0].size())
        {
            if (target == matrix[i][j])
            {
                return true;
            }
            else if (target > matrix[i][j])
            {
                j++;
            }
            else
            {
                i--;
            }
        }
        return false;
    }
};
// @lc code=end
