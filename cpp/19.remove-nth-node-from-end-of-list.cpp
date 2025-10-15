/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //dummy是一个虚拟头节点，目的是方便删除第一个节点的情况
        ListNode dummy(0);
        ListNode* cur=&dummy;
        dummy.next=head;
        ListNode* ptr=&dummy;

        int steps=n+1;
        while(steps--)
            ptr=ptr->next;

        while(ptr){
            cur=cur->next;
            ptr=ptr->next;
        }

        ListNode* del=cur->next;
        cur->next=cur->next->next;
        delete del;

        //不直接返回head是因为head有可能被del
        return dummy.next;
    }
};
// @lc code=end

