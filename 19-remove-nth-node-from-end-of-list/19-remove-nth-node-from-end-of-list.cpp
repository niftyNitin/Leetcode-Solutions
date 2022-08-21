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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* ahead = head;
        ListNode* behind = dummy;
        for(int i = 1; i < n; i++)
            ahead = ahead->next;
        
        while(ahead->next) {
            ahead = ahead->next;
            behind = behind->next;
        }
        behind->next = behind->next->next;
        return dummy->next;
    }
};