/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int>> res;
        unordered_map<int,bool> used;
        vector<int> ans;
        //这里要排序，以便判断
        sort(nums.begin(),nums.end());

        for(int i=0;i<len;i++)
            used[i]=false;

        function<void(int)> backtrack=[&](int idx){
            if(idx==len){
                res.push_back(ans);
                return;
            }

            
            for(int i=0;i<len;i++){
                //剪枝 这一层和上一层的一致且上一层的没有被用过，因为上一层的同样大小的数在某个循环里面在同一层肯定会被用过，所以这里不用，保证同一层不会出现相同的数
                if(i>0&&nums[i]==nums[i-1]&&!used[i-1])continue;
                if(!used[i]){
                    ans.push_back(nums[i]);
                    used[i]=true;
                    backtrack(idx+1);

                    ans.pop_back();
                    used[i]=false;
                }
            }
        };

        backtrack(0);

        return res;
    }
};
// @lc code=end

