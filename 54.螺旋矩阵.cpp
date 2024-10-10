/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        /*
        用一种四处碰壁的写法，每次碰壁就转向，向右向下向左向上，每次碰壁就缩小边界
        用四个边界top、bottom、left、right来控制
        */

        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;
        vector<int> res;

        while (left <= right && top <= bottom)
        {
            // 向右
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;

            // 向下
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;

            // 向左，注意这里的left<=right是为了防止重复元素
            if (left <= right && top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // 向上：注意这里的left<=right是为了防止重复元素
            if (top <= bottom && left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            /*
            这里不能同意加减，因为有可能会出现重复元素
            left++;
            right--;
            top++;
            bottom--;
            */
        }
        return res;
    }
};
// @lc code=end
