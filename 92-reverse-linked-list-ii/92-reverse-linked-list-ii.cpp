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
        ListNode* nhead = new ListNode();
        nhead->next = head;
        ListNode* lft = nhead->next;
        ListNode* prev = nhead;
        int i = 1;
        while(i < left) {
            i++;
            prev = prev->next;
            lft = lft->next;
        } 
        ListNode* curr = lft;
        ListNode* p = NULL;
        ListNode* nxt = NULL;
        
        
        while(i <= right) {
            i++;
            nxt = curr->next;
            cout << curr->val << " ";
            curr->next = p;
            p = curr;
            curr = nxt;
        }
        
        prev->next = p;
        lft->next = curr;
        return nhead->next;
    }
};