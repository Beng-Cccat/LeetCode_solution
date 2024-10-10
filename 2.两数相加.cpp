/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 用进位的知识做
        ListNode *head = new ListNode();
        ListNode *cur = head;
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        int add = 0;
        int mod = 0;
        int div = 0;
        while (p1 != NULL || p2 != NULL)
        {
            if (p1 != NULL && p2 != NULL)
            {
                add = p1->val + p2->val + div;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1 != NULL)
            {
                add = p1->val + div;
                p1 = p1->next;
            }
            else if (p2 != NULL)
            {
                add = p2->val + div;
                p2 = p2->next;
            }
            mod = add % 10;
            div = add / 10;
            ListNode *newNode = new ListNode(mod);
            cur->next = newNode;
            cur = cur->next;
        }

        if (div != 0)
        {
            ListNode *newNode = new ListNode(div);
            cur->next = newNode;
        }
        return head->next;
    }
};
// @lc code=end
