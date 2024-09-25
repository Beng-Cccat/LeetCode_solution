/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        // 初始化
        /*
        1. left用于链接反转后的起始位置的前一个，主要用于链接反转后的头节点
        2. right作为链接反转后的终止位置，主要用于将后文节点断开，便于判断结束时机
        3. 由于最后要返回头节点，但是这个过程中left和right一直在变，不好确认头节点的位置，所以特地使用一个节点preNode标识头节点前面的节点
        这样在反转过程中preNode会自动链接到反转后的头节点
        */
        ListNode *preNode = new ListNode(0, head);
        ListNode *left = preNode;
        ListNode *right = preNode;
        // 该k个节点的起始位置
        ListNode *start = left->next;
        while (1)
        {
            // 找到right的位置
            for (int i = 0; right != NULL && i < k; i++)
            {
                right = right->next;
            }
            // 不够k的，不进行翻转
            if (right == NULL)
                break;

            // 断开链接前要先标识该节点
            ListNode *nextstart = right->next;

            // 断开连接，方便后面判断
            right->next = NULL;

            // 反转k个节点，该函数返回反转后的起始位置
            // 链接头部
            left->next = reverse(start);
            // 链接尾部
            start->next = nextstart;

            // 重新初始化，准备进行下一次循环
            left = start;
            right = start;
            start = start->next;
        }
        return preNode->next;
    }
    ListNode *reverse(ListNode *head)
    {
        // cur表示当前反转到哪个节点了，即当前反转链表的头节点
        // precur表示当前反转节点的前一个节点，作为最后返回的头节点的前一个节点
        ListNode *cur = head;
        ListNode *precur = NULL;
        while (cur != NULL)
        {
            ListNode *aftcur = cur->next;
            cur->next = precur;
            precur = cur;
            cur = aftcur;
        }
        return precur;
    }
};
// @lc code=end
