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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)   return head;
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        ListNode* curr = head;
        while(curr) {
            if(!curr->next or curr->val != curr->next->val) {
                tail->next = curr;
                tail = tail->next;
                curr = curr->next;
            } 
            else {
                int x = curr->val;
                while(curr and curr->val == x) {
                    curr = curr->next;
                }
            }
        }
        tail->next = NULL;
        return dummy->next;
    }
};