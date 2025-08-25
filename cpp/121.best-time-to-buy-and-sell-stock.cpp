/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //如果第i天卖出股票，则最大利润为（该天的股价-前面天数中最小的股价），然后与已知的最大利润作比较
        int days=prices.size();
        vector<int> minPrice(days,0);

        minPrice[0]=prices[0];
        for(int i=1;i<days;i++)
            minPrice[i]=min(minPrice[i-1],prices[i]);

        int res=0;
        for(int i=0;i<days;i++){
            int temp=prices[i]-minPrice[i];
            res=max(res,temp);
        }
        return res;
    }
};
// @lc code=end

