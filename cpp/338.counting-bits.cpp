/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            int count=0;
            int data=i;
            while(data){
                data&=(data-1);
                count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
// @lc code=end

