/*
 * @lc app=leetcode.cn id=123 lang=java
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public int maxProfit(int[] prices) {
        /*
         * 动态规划：
         * 几个交易状态：
	        1.	dp[i][0]：在第 i 天结束时，未进行任何交易的最大利润（恒为 0）。
            2.	dp[i][1]：在第 i 天结束时，买入第一笔
            3.	dp[i][2]：在第 i 天结束时，卖出第一笔
            4.  dp[i][3]：在第 i 天结束时，买入第二笔
            5.  dp[i][4]：在第 i 天结束时，卖出第二笔

         * 状态转移方程：
            •	初始状态：
            •	dp[0][0] = 0（未进行交易，利润为 0）
            •	dp[0][1] = -prices[0]（第一天买入股票，利润为 -prices[0]）
            •	dp[0][2] = 0（当天买当天卖）
            •	dp[0][3] = -prices[0]（相当于买入第二笔）
            •	dp[0][4] = 0（相当于第二笔也卖了）
         * 转移状态：
            •	dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
            •	dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i])
            •	dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
            •	dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
         */

        int n=prices.length;
        int[][] dp=new int[n][5];
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        dp[0][2]=0;
        dp[0][3]=-prices[0];
        dp[0][4]=0;
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=Math.max(dp[i-1][1],dp[i-1][0]-prices[i]);
            dp[i][2]=Math.max(dp[i-1][2],dp[i-1][1]+prices[i]);
            dp[i][3]=Math.max(dp[i-1][3],dp[i-1][2]-prices[i]);
            dp[i][4]=Math.max(dp[i-1][4],dp[i-1][3]+prices[i]);
        }
        return dp[n-1][4];

        /*
         * 改进：依旧可以直接使用五个变量进行代替
         */
    }


    public int maxProfit_193(int[] prices) {
        /*
         * 改了II的贪心算法
         * 这里的问题是什么呢
         * 忽略了交易的完整性，可能会遗漏更优的交易
         */
        List<Integer> up=new LinkedList<>();
        int n=prices.length;
        Integer num=0;
        for(int i=1;i<n;i++){
            if(prices[i]>=prices[i-1]){
                num+=prices[i]-prices[i-1];
            }
            else{
                up.add(num);
                num=0;
            }
        }
        if(num!=0)
            up.add(num);

        //判断特殊情况
        if(up.size()==0)
            return 0;
        else if(up.size()==1)
            return up.get(0);
        //排序默认升序，所以这里用一个参数表示降序
        Collections.sort(up,Collections.reverseOrder());
        return up.get(0)+up.get(1);
    }
}
// @lc code=end

