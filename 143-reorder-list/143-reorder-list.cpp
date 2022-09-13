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
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        ListNode* nxt = NULL;
        slow->next = NULL;
        
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        ListNode* start = head;
        ListNode* end = prev;
        
        while(start and end) {
            ListNode* temp1 = start->next;
            ListNode* temp2 = end->next;
            start->next = end;
            end->next = temp1;
            start = temp1;
            end = temp2;
        }
    }
};