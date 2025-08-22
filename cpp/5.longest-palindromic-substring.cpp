/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome_1(string s) {
        //dp[i][j]表示s[i][j]是否是回文字符串
        int lens=s.size();
        vector<vector<bool>> dp(lens,vector<bool>(lens,false));

        //由于最后要用substr进行分割，所以前面需要进行初始索引和长度的标识
        int pos=0;
        int len=1;

        //初始化
        for(int i=0;i<lens;i++)
            dp[i][i]=true;

        //对长度进行枚举
        for(int L=2;L<=lens;L++){
            //i表示开头
            for(int i=0;i<=lens-L;i++){
                int j=i+L-1;
                if(s[i]!=s[j])
                    continue;
                if(L==2||L==3){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=dp[i+1][j-1];
                }

                //更新长度
                //如果两边只要相等就会进行判断，这是不对的，所以这里需要加一个，只有当这一段是回文串再开始判断才ok
                if(L>len&&dp[i][j]){
                    len=L;
                    pos=i;
                }
            }

        }

        return s.substr(pos,len);
    }

    string longestPalindrome(string s) {
        //中心扩展法+匿名函数

        //老样子，由于最后需要pos和len进行substr，所以：
        int pos=0,len=1;
        int lens=s.size();

        //匿名函数
        //[&]表示按引用捕获外部所有变量，函数体内可以直接访问并修改外部变量pos、len、s、lens
        auto expandAroundCenter=[&](int left,int right){
            //left和right表示左右边界
            while(left>=0&&right<lens&&s[left]==s[right]){
                if(len<right-left+1){
                    pos=left;
                    len=right-left+1;
                }
                left--;
                right++;
            }
        };

        for(int i=0;i<lens;i++){
            //偶数
            expandAroundCenter(i,i);
            //奇数
            expandAroundCenter(i,i+1);
        }

        return s.substr(pos,len);
    }
};
// @lc code=end

