/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        //不适用/和%，使用左移符号模拟

        //INT_MIN = -2,147,483,648 （即 -2³¹）
        //INT_MAX = 2,147,483,647 （即 2³¹ - 1）
        //当dividend == INT_MIN && divisor == -1时理论上结果应该是INT_MIN / -1 = 2,147,483,648
        //但是这个值超过了 INT_MAX（最大能表示到 2,147,483,647），所以会发生整数溢出（undefined behavior）
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        //使用long long防止溢出
        long long a=abs((long long)dividend);
        long long b=abs((long long)divisor);
        long long res=0;

        //multiple表示倍数
        long long multiple=1;
        //b<<1表示b*2
        //循环跳出条件是a<b，即multiple已经达到他的最大值
        while(a>=b){
            long long temp=b,multiple=1;
            //以指数形式增加，提高速度
            while(a>=(temp<<1)){
                temp<<=1;
                multiple<<=1;
            }
            a-=temp;
            res+=multiple;
        }

        //判断符号
        if ((dividend < 0) ^ (divisor < 0))
            res = -res;
        return res;
    }
};
// @lc code=end

