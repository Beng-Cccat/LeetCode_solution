/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //利用单调栈，找到左侧更大的元素和右侧更大的元素即是宽，该索引下的height值即是高

        int res=0;

        int len=heights.size();

        vector<int> right(len);
        stack<int> s;

        for(int i=len-1;i>=0;i--){
            while(!s.empty()&&heights[s.top()]>=heights[i])
                s.pop();
            
            right[i]=s.empty()?len:s.top();
            s.push(i);
        }

        s=stack<int>();
        vector<int> left(len);
        for(int i=0;i<len;i++){
            while(!s.empty()&&heights[s.top()]>=heights[i])
                s.pop();
            
            left[i]=s.empty()?-1:s.top();
            s.push(i);
        }

        for(int i=0;i<len;i++){
            res=max(res,heights[i]*(right[i]-left[i]-1));
        }
        return res;
    }
};
// @lc code=end

