/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 特殊情况
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        // 开始合并
        ListNode *head = new ListNode();
        ListNode *cur = head;
        ListNode *cur1 = list1;
        ListNode *cur2 = list2;

        while (cur1 != NULL && cur2 != NULL)
        {
            if (cur1->val < cur2->val)
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        while (cur1 != NULL)
        {
            cur->next = cur1;
            cur1 = cur1->next;
            cur = cur->next;
        }
        while (cur2 != NULL)
        {
            cur->next = cur2;
            cur2 = cur2->next;
            cur = cur->next;
        }
        return head->next;
    }
};
// @lc code=end
