/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        vector<int> temp;

        function<void(int)> backtrack=[&](int index){
            //终止条件
            if(index==nums.size()){
                result.push_back(temp);
                return;
            }

            //回溯：对于当前对应的元素，选择加入或者不加入
            backtrack(index+1); //直接进入下一层

            temp.push_back(nums[index]);
            backtrack(index+1); //状态变化后进入下一层
            temp.pop_back();    //状态还原
        };

        backtrack(0);
        return result;
    }
};
// @lc code=end

