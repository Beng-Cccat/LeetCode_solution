/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res=0,len1=nums1.size(),len2=nums2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));

        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    res=max(res,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return res;
    }

};
// @lc code=end

