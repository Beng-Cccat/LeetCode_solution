/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        vector<int> dp;

        function<void(int,int)> backtrack=[&](int sum,int start){
            if(sum==target){
                res.push_back(dp);
                return;
            }

            for(int i=start;i<candidates.size();i++){
                if(sum+candidates[i]<=target){
                    dp.push_back(candidates[i]);
                    backtrack(sum+candidates[i],i);
                    dp.pop_back();
                }
            }
        };

        backtrack(0,0);

        return res;
    }
};
// @lc code=end

