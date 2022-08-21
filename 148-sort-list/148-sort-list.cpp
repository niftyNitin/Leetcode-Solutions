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
private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeList(ListNode* left, ListNode* right) {
        if(!left)   return right;
        if(!right)  return left;
        
        ListNode* res;
        if(left->val < right->val) {
            res = left;
            res->next = mergeList(left->next, right);
        }
        else {
            res = right;
            res->next = mergeList(left, right->next);
        }
        return res;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        // split list into two halves
        ListNode* left = head;
        ListNode* right = findMiddle(head);
        ListNode* temp = right->next;
        right->next = NULL;
        right = temp;
        
        left = sortList(left);
        right = sortList(right);
        
        return mergeList(left, right);
    }
};