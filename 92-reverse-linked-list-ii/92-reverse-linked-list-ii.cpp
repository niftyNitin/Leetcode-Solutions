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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // inserting a dummy node before the head to avoid egde case where left=1;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        // shifting the curr pointer to left index
        for(int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }
        
        // reversing from left to right
        ListNode* p = NULL;
        ListNode* n = NULL;
        ListNode* c = curr;
        for(int i = left; i <= right; i++) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        
        prev->next = p;
        curr->next = n;
        return dummy->next;
    }
};