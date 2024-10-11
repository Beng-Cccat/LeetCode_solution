/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        unordered_map<Node *, Node *> mp;
        Node *cur = head;
        // 先构建所有的节点
        while (cur != NULL)
        {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        // 添加next和random指针
        cur = head;
        while (cur != NULL)
        {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};
// @lc code=end
