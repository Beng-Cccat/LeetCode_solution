/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
    //本质是爬楼梯
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target+1,-1);
        

        function<int(int)> dp=[&](int sum){
            //base
            if(sum==0)return 1;
            if(sum<0)return 0;

            //记忆化 避免重复搜索
            if(memo[sum]!=-1)return memo[sum];

            int count=0;
            for(auto num:nums)
                count+=dp(sum-num);
            return memo[sum]=count;
        };
        return dp(target);
    }
};
// @lc code=end

