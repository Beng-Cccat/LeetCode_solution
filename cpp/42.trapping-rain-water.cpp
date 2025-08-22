/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 一层一层查看 时间复杂度高
        /*
        int result=0;
        int maxVal=*max_element(height.begin(),height.end());
        for(int level=1;level<=maxVal;level++){
            int left=0;
            while(left<height.size()){
                if(height[left]<level){
                    left++;
                    continue;
                }
                int right=left+1;
                while(right<height.size()&&height[right]<level){
                    right++;
                }
                if(right!=height.size())
                    result+=right-left-1;
                left=right;
            }
        }
        return result;
        */

        //min(左边最高柱子, 右边最高柱子) - height[i]
        int left=0,right=height.size()-1;
        int leftMax=height[left],rightMax=height[right];
        int result=0;
        int cur=0;
        while(left<right){
            if(height[left]<height[right]){ //左边柱子更低，当前柱子以和左边柱子差值积水
                if(height[left]>=leftMax)   //当前柱子高于左边柱子，该柱子无法积水
                    leftMax=height[left];
                else
                    result+=leftMax-height[left];
                left++;
            }
            else{
                if(height[right]>=rightMax)
                    rightMax=height[right];
                else
                    result+=rightMax-height[right];
                right--;
            }
        }
        return result;
    }
};
// @lc code=end

