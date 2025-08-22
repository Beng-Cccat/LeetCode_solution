/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0)return {};

        vector<string> result;
        string str;

        function<void(int,int)> backtrack=[&](int left,int right){
            if(left+right==2*n){
                result.push_back(str);
                return;
            }

            if(left==n){    //左括号上限，只能加右括号
                str.push_back(')');
                backtrack(left,right+1);
                str.pop_back();
            }
            else if(left==right){   //左右括号相等，只能加左括号
                str.push_back('(');
                backtrack(left+1,right);
                str.pop_back();
            }
            else{   //左括号>右括号，什么都能加
                str.push_back('(');
                backtrack(left+1,right);    //状态变化
                str.pop_back();             //回溯

                str.push_back(')');
                backtrack(left,right+1);
                str.pop_back();
            }

        };

        backtrack(0,0);

        return result;
    }
};
// @lc code=end

