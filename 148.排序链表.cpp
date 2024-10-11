/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode *sortList(ListNode *head)
    {
        // 特殊情况
        if (head == NULL || head->next == NULL)
            return head;

        // 内部基于红黑树进行排序，时间复杂度为O(nlogn)
        // 另一种方法是使用归并排序，时间复杂度依旧为O(nlogn)
        map<int, vector<ListNode *>> mp;
        ListNode *cur = head;
        while (cur != NULL)
        {
            mp[cur->val].push_back(cur);
            cur = cur->next;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        dummy->next = NULL;
        for (auto &[val, nodes] : mp)
        {
            for (auto node : nodes)
            {
                pre->next = node;
                pre = pre->next;
            }
        }
        // 这里必须释放最后一个节点的next指针，否则会形成环
        pre->next = NULL;
        return dummy->next;
    }
};
// @lc code=end
