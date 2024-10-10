/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        /*
        把两个链表拼接起来，A+B和B+A，这样两个链表的长度就一样了
        如果有交点，那么在交点处就会相遇
        即skipA+相交链表长度+skipB = skipB+相交链表长度+skipA
        然后两个指针就会指向同一个节点
        */
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != p2)
        {
            p1 = p1 == nullptr ? headB : p1->next;
            p2 = p2 == nullptr ? headA : p2->next;
        }
        return p1;
    }
};
// @lc code=end
