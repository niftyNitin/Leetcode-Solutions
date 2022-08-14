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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    ListNode* findMiddle(ListNode* head, ListNode* tail) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail and fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail = NULL) {
        if(head == tail)    return NULL;
        ListNode* middle = findMiddle(head, tail);
        
        TreeNode* root = new TreeNode(middle->val);
        root->left = sortedListToBST(head, middle);
        root->right = sortedListToBST(middle->next, tail);
        
        return root;
    }
};





