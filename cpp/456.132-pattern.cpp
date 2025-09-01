/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();

        if(n<3)
            return false;

        stack<int> st;
        int res=INT_MIN;//当前最大的合法nums[k]
        for(int i=n-1;i>=0;i--){
            if(nums[i]<res)return true;
            while(!st.empty()&&nums[i]>st.top()){
                res=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;

    }
};
// @lc code=end

