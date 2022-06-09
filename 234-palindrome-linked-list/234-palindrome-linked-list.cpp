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
    bool isPalindrome(ListNode* head) {
        // handling the case where only one node
        if(!head->next) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        
        // finding the middle of the list
        while(fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // reversing the list from the middle point
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        
        while(curr) {
            if(curr = slow) {
                while(curr) {
                    nxt = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nxt;
                }
                break;
            }
            
            prev = curr;
            curr = curr->next;
        }
        
        // traversing the list from both ends to check palindrome
        ListNode* temp = head;
        ListNode* prevc = prev;
        while(temp != slow) {
            if(temp->val != prev->val)  return false;
            temp = temp->next;
            prev = prev->next;
        }
        
        prev = NULL;
        curr = prevc;
        nxt = NULL;
        while(curr != slow) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return true;
    }
};