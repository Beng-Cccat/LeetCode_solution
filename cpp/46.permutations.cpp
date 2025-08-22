/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        vector<int> single;
        unordered_map<int,bool> used;
        for(int i=0;i<nums.size();i++)
            used[i]=false;

        function<void(int)> backtrack=[&](int index){
            //终止条件
            if(index==nums.size()){
                result.push_back(single);
                return;
            }

            //穷举每一个可能的字符
            for(int i=0;i<nums.size();i++){
                if(!used.at(i)){
                    single.push_back(nums[i]);
                    used[i]=1;  //状态变化
                    backtrack(index+1); //回溯
                    used[i]=0;
                    single.pop_back();  //还原状态
                }
            }
        };

        backtrack(0);

        return result;
    }
};
// @lc code=end

