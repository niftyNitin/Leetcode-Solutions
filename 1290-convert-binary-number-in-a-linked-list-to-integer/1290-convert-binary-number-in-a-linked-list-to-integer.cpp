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
    int getDecimalValue(ListNode* head) {
        ListNode *curr = head;
        
        // calculating the decimal value
        string res = "";
        while(curr) {
            res += (curr->val + '0');
            curr = curr->next;
        }
        return stoi(res, 0, 2);
    }
};