/*
 * @lc app=leetcode.cn id=121 lang=java
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public int maxProfit_wj(int[] prices) {
        //int[]复制可以使用Arrays.copyOf或者System.arraycopy
        int[] maxget=Arrays.copyOf(prices, prices.length);
        List<Integer> maxprofit=new LinkedList<>();
        int n=prices.length;
        for(int i=n-2;i>=0;i--){
            maxget[i]=Math.max(prices[i], maxget[i+1]);
            maxprofit.add(Math.max(maxget[i]-prices[i],0));
        }

        if(maxprofit.size()!=0)
            return Collections.max(maxprofit);
        return 0;
    }

    public int maxProfit(int[] prices) {
        int n=prices.length;
        int maxprice=prices[n-1];
        int maxprofit=0;
        for(int i=n-1;i>=0;i--){
            maxprice=Math.max(maxprice,prices[i]);
            maxprofit=Math.max(maxprofit, maxprice-prices[i]);
        }

        return maxprofit;
    }
}
// @lc code=end

