/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA=headA;

        while(pA!=NULL){
            ListNode* pB=headB;
            while(pB!=NULL){
                if(pA!=pB)
                    pB=pB->next;
                else
                    return pA;
            }
            pA=pA->next;
        }
        return NULL;
    }
};
// @lc code=end

