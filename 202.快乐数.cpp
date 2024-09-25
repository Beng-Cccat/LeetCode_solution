/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        /*
        1. 快慢指针，由于无限循环即说明有环，所以可以用快慢指针来判断
        2. 用hash判断是否该结果在前面出现过，如果出现过则说明无限循环
        */

        int slow = n;
        int fast = n;
        slow = getsquare(slow);
        fast = getsquare(getsquare(fast));

        while (slow != fast)
        {
            slow = getsquare(slow);
            fast = getsquare(getsquare(fast));
        }

        if (slow == 1)
            return true;
        else
            return false;
    }
    int getsquare(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};
// @lc code=end
