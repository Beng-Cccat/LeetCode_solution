/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses_stack(string s) {
        int maxLen=0;

        /*
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                //不连续
                if(!st.empty()){
                    st.pop();
                    maxLen+=2;
                }
            }
        }
        return maxLen;
        */

        //正确处理连续情况，需要使用基准元素
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            else{
                //右括号的时候，我先弹出一个，如果弹出后栈为空，说明前面没有左括号，弹出的是基准元素
                st.pop();
                if(st.empty()){ //此时需要再弹入一个基准元素，以此判断栈中原先是否有左括号
                    st.push(i);
                }
                else{   //如果不为空，则说明刚刚的右括号可以有匹配
                    maxLen=max(maxLen,i-st.top());

                }
            }
        }
        return maxLen;
    }

    int longestValidParentheses(string s) {
        vector<int> dp(s.size(),0);
        int maxLen=0;

        for(int i=1;i<s.size();i++){
            if(s[i]=='(')
                continue;
            //s[i]==')'
            //不用判断i-1>=0也可因为i从1开始肯定i-1>=0
            if(i-1>=0&&s[i-1]=='('){    //直接匹配
                //如果s[i-2]越界就直接为2，如果不越界就是dp[i-2]+2
                dp[i]=(i>=2?dp[i-2]:0)+2;
            }
            //现在就是i-1>=0（肯定）&&s[i-1]==')'的情况
            //dp[i-1]表示的就是上一批完整括号对的数量
            //i-dp[i-1]-1表示的位置是...*()())
            else if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                dp[i]=dp[i-1]+2;
                //看看要不要和前面独立的连接
                //i-dp[i-1]-2表示的位置是...*(...)
                if(i-dp[i-1]-2>=0){
                    dp[i]+=dp[i-dp[i-1]-2];
                }
            }
            maxLen=max(maxLen,dp[i]);
        }
        return maxLen;
    }
};
// @lc code=end

