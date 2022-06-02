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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while(list1 and list2) {
            ListNode* temp = new ListNode();
            if(list1->val < list2->val) {
                temp->val = list1->val;
                list1 = list1->next;                
            }
            else {
                temp->val = list2->val;
                list2 = list2->next;                
            }
            
            tail->next = temp;
            tail = tail->next;
        }
        
        if(list1)   tail->next = list1;
        if(list2)   tail->next = list2;
        
        return head->next;
    }
};