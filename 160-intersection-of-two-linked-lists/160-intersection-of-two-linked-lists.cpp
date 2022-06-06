/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA) {
            lenA++;
            tempA = tempA->next;
        }
        
        while(tempB) {
            lenB++;
            tempB = tempB->next;
        }
        
        tempA = headA;
        tempB = headB;
        
        int x = abs(lenA - lenB);
        if(lenA > lenB) {
            while(x--) {
                tempA = tempA->next;
            }
        }
        else {
            while(x--) {
                tempB = tempB->next;
            }
        }
        
        while(tempA and tempB) {
            if(tempA == tempB)  return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return NULL;
    }
};