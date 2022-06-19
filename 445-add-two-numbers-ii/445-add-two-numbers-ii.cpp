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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1 or l2) {
            if(l1)  s1.push(l1->val), l1 = l1->next;
            if(l2)  s2.push(l2->val), l2 = l2->next;
        }
        
        int carry = 0;
        ListNode* curr = NULL;
        while(!s1.empty() or !s2.empty()) {
            int x = 0, y = 0;
            if(!s1.empty()) x = s1.top(), s1.pop();
            if(!s2.empty()) y = s2.top(), s2.pop();
            int digit = x + y + carry;
            carry = digit/10;
            ListNode* node = new ListNode(digit%10);
            node->next = curr;
            curr = node;
        }
        if(carry) {
            ListNode* node = new ListNode(carry);
            node->next = curr;
            curr = node;
        }
        
        return curr;
    }
};