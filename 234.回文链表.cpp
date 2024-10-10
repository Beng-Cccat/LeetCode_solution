/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head)
    {
        vector<int> vals;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            vals.push_back(cur->val);
            cur = cur->next;
        }

        for (int i = 0; i < vals.size() / 2; i++)
        {
            if (vals[i] != vals[vals.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
