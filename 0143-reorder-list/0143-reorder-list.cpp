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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reversing from mid to end
        ListNode* prev = NULL; 
        ListNode* curr = slow->next;
        ListNode* next = NULL;
        
        slow->next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        
        // using two pointers to add alternate nodes to a dummy head
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        
        ListNode *head1 = head, *head2 = prev;
        while(head1 or head2) {
            if(head1) {
                tail->next = head1;
                head1 = head1->next;
                tail = tail->next;
            }
            if(head2) {
                tail->next = head2;
                head2 = head2->next;
                tail = tail->next;
            }
        }
        
        head = dummy->next;
    }
};