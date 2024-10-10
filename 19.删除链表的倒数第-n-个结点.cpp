/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 虚拟节点的使用：重要
        ListNode *dummy = new ListNode(0);
        ListNode *slow = dummy; // 表示需要删除的节点前面的节点
        ListNode *fast = dummy; // 用于定位的节点
        dummy->next = head;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 定位成功，开始删除
        ListNode *del = slow->next;
        slow->next = del->next;

        // 确保如果唯一节点被删除，返回值为 nullptr
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
// @lc code=end
