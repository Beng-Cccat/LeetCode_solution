/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        int res=INT_MAX;
        int step=0;

        function<void(long long)> backtrack=[&](long long index){
            //终止条件
            if(index==1){
                res=min(res,step);
                return;
            }

            if (step >= res) return;  // 剪枝

            //穷举每一个可能的元素
            if(index%2){
                step++;
                backtrack(index+1);
                backtrack(index-1);
                step--;
            }
            else{
                step++;
                backtrack(index/2);
                step--;
            }
        };

        backtrack(n);

        return res;
    }
};
// @lc code=end

