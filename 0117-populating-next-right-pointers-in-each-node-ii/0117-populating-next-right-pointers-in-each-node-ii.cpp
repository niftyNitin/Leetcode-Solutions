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
        if(!root)   return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            auto node = q.front();
            q.pop();
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
            while(--n) {
                auto node2 = q.front();
                q.pop();
                if(node2->left)  q.push(node2->left);
                if(node2->right) q.push(node2->right);
                node->next = node2;
                node = node2;
            }
        }
        
        return root;
    }
};