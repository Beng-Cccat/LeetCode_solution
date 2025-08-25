/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int res;
        vector<int> steps(n+1);
        if(n==1)return 1;
        if(n==2)return 2;

        //初始化
        steps[1]=1;
        steps[2]=2;

        //遍历状态
        for(int i=3;i<=n;i++){
            steps[i]=steps[i-1]+steps[i-2];
        }

        return steps[n];
    }
};
// @lc code=end

