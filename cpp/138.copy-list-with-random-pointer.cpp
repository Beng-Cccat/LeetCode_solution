/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //重点：原节点和新节点的映射关系

        //思路一：哈希表表示源节点和新节点的映射关系
        unordered_map<Node*,Node*> hp;
        Node* ptr=head;
        while(ptr){
            hp[ptr]=new Node(ptr->val);
            ptr=ptr->next;
        }

        ptr=head;
        while(ptr){
            hp[ptr]->next=ptr->next?hp[ptr->next]:NULL;
            hp[ptr]->random=ptr->random?hp[ptr->random]:NULL;
            ptr=ptr->next;
        }

        return hp[head];

        //思路二：将新节点放在源节点后面，然后再进行连接
    }
};
// @lc code=end

