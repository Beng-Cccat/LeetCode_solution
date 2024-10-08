/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 先找环的长度，再用先后指针找环的入口
        ListNode *slow = head;
        ListNode *fast = head;
        while (1)
        {
            if (fast == NULL || fast->next == NULL)
            {
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break;
            }
        }
        // 找环的长度
        int len = 1;
        fast = fast->next;
        while (slow != fast)
        {
            fast = fast->next;
            len++;
        }

        // 找环的入口
        slow = head;
        fast = head;
        for (int i = 0; i < len; i++)
        {
            fast = fast->next;
        }
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
// @lc code=end
