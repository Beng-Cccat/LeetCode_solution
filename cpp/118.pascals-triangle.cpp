/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int i=0;i<numRows;i++){
            vector<int> tmp(i+1,1);
            for(int j=0;j<i;j++)
                if(j!=0&&j!=i)
                    tmp[j]=res[i-1][j-1]+res[i-1][j];
                else if(j==0||j==i)
                    tmp[j]=1;
            res.push_back(tmp);
        }

        return res;
    }
};
// @lc code=end

