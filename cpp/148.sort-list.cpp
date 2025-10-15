/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList_TLE(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* a=head;
        while(a->next!=NULL){
            ListNode* b=a->next;
            while(b!=NULL){
                if(a->val>b->val){
                    swap(a->val,b->val);
                }
                b=b->next;
            }
            a=a->next;
        }

        return head;
    }

    ListNode* merge(ListNode* left,ListNode* right){
        ListNode dummy(0);
        ListNode* cur=&dummy;

        //两边都还有元素的时候才这么比较 不然就是直接连接就可以了
        while(left&&right){
            if(left->val<=right->val){
                cur->next=left;
                left=left->next;
            }

            else if(left->val>right->val){
                cur->next=right;
                right=right->next;
            }
            cur=cur->next;
        }

        cur->next=left?left:right;

        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        //O(nlogn)的有归并排序、快速排序、堆排序、希尔排序
        if(!head||!head->next)return head;

        //用快慢指针找到中点
        ListNode* slow=head;
        ListNode* fast=slow->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        //分成两个部分
        ListNode* mid=slow->next;
        slow->next=NULL;

        //递归排序
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);

        //合并
        return merge(left,right);

    }
};
// @lc code=end

