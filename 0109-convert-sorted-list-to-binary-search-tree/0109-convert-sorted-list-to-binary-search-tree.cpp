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
public:    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)       return NULL;
        if(!head->next) new TreeNode(head->val);
        ListNode *slow = head, *fast = head, *slowprev = NULL;
        while(fast and fast->next) {
            slowprev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        TreeNode* right = sortedListToBST(slow->next);
        if(slowprev) {
            slowprev->next = NULL;
            TreeNode* left = sortedListToBST(head);
            root->left = left;
        }
        else    root->left = NULL;
        root->right = right;
        return root;
    }
};