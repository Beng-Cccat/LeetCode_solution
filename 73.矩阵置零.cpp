/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> zerocol;
        set<int> zerorow;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    zerocol.insert(j);
                    zerorow.insert(i);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (auto it = zerocol.begin(); it != zerocol.end(); it++)
            {
                // 注意在这里要加*
                matrix[i][*it] = 0;
            }
        }

        for (auto it = zerorow.begin(); it != zerorow.end(); it++)
        {
            // 这里不能用clear，因为clear清空了vector的元素，会变成[]，但是vector的大小还是不变的
            matrix[*it].assign(matrix[0].size(), 0);
        }
    }
};
// @lc code=end
