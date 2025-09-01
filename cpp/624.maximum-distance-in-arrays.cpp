/*
 * @lc app=leetcode id=624 lang=cpp
 *
 * [624] Maximum Distance in Arrays
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        //维护全局最大值和全局最小值
        int minn=arrays[0][0];
        int maxn=arrays[0][arrays[0].size()-1];
        int res=0;

        for(int i=1;i<arrays.size();i++){
            int sub1=arrays[i][arrays[i].size()-1]-minn;
            int sub2=maxn-arrays[i][0];
            res=max({res,sub1,sub2});
            minn=min(minn,arrays[i][0]);
            maxn=max(maxn,arrays[i][arrays[i].size()-1]);

        }
        return res;
    }
};
// @lc code=end

