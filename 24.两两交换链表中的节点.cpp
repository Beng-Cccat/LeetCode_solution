/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 特殊情况
        if (head == NULL || head->next == NULL)
            return head;

        // 仍然是用两个指针进行交换
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *cur = pre->next;
        ListNode *next = cur->next;
        while (cur != NULL && next != NULL)
        {
            cur->next = next->next;
            next->next = cur;
            pre->next = next;

            pre = cur;
            cur = cur->next;
            next = cur == NULL ? NULL : cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end
