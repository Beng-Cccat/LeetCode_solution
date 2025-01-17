/*
 * @lc app=leetcode.cn id=122 lang=java
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public int maxProfit(int[] prices) {
        /*
         * 贪心算法：找到所有的上升区间
         */
        int max_pro=0;
        for(int i=1;i<prices.length;i++){
            if(prices[i]>=prices[i-1])
                max_pro+=prices[i]-prices[i-1];
        }
        return max_pro;
    }

    public int maxProfit_ok(int[] prices) {
        /*
         * 动态规划版本：
         * 定义两个状态：
	        1.	dp[i][0]：第 i 天结束时不持有股票的最大利润。
	        2.	dp[i][1]：第 i 天结束时持有股票的最大利润。

         * 状态转移方程：
	        •	dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
	        •	今天不持有股票，要么昨天也不持有，要么昨天持有并在今天卖出。
	        •	dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
	        •	今天持有股票，要么昨天也持有，要么昨天不持有并在今天买入。

         * 初始条件：
            •	dp[0][0] = 0（第 0 天不持有股票，利润为 0）
            •	dp[0][1] = -prices[0]（第 0 天持有股票，利润为 -prices[0]）
         */

        int[][] dp=new int[prices.length][2];
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<prices.length;i++){
            dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=Math.max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[prices.length-1][0];

        /*
         * 进一步优化：
         * 因为第二天状态只依赖于前一天的状态，所以可以用两个变量代替这两个数组
         */
    }


    int maxprofit=0;
    int[] prices;
    public int maxProfit_exceed(int[] prices) {
        this.prices=Arrays.copyOf(prices,prices.length);
        
        //这个冗余太高，本题会超时（但是逻辑应该是对的）
        dfs(0,0,0);

        return maxprofit;
    }

    void dfs(int buy,int sell,int profit){
        if(buy==prices.length){
            maxprofit=Math.max(maxprofit,profit);
            return;
        }
        if(sell>prices.length-1)
            return;

        //卖
        if(prices[sell]>prices[buy]){
            profit+=prices[sell]-prices[buy];
            dfs(sell+1,sell+1,profit);

            //回溯
            profit=profit-(prices[sell]-prices[buy]);
        }

        //不卖
        dfs(buy,sell+1,profit);

        //不买
        dfs(buy+1,buy+1,profit);
    }
}
// @lc code=end

