/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs_3pairs(ListNode* head) {
        if(!head || !head->next) return head;

        
        ListNode* mid=head;
        ListNode* back=head->next;
        ListNode* front=NULL;

        head=back;
        while(back!=NULL){
            mid->next=back->next;
            back->next=mid;
            if(front){
                front->next=back;
            }
            front=mid;
            mid=mid->next;
            back=mid?mid->next:NULL;
        }
        return head;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;

        //以第一个节点为循环，交换该节点后两个节点
        while(prev->next&&prev->next->next){
            ListNode* a=prev->next;
            ListNode* b=a->next;

            //swap
            a->next=b->next;
            b->next=a;
            prev->next=b;

            //move
            prev=a;
        }

        return dummy.next;
    }
};
// @lc code=end

