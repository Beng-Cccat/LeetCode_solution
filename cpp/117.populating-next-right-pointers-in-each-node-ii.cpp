/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return {};
        queue<Node*> st;
        st.push(root);

        while(!st.empty()){
            int len=st.size();
            for(int i=0;i<len;i++){
                Node* temp=st.front();
                st.pop();
                if(i!=len-1)
                    temp->next=st.front();
                if(temp->left)
                    st.push(temp->left);
                if(temp->right)
                    st.push(temp->right);

            }
        }
        return root;
    }
};
// @lc code=end

