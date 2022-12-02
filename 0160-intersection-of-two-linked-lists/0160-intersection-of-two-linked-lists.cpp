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
        ListNode *nodeA = headA, *nodeB = headB;
        while(nodeA or nodeB) {
            if(!nodeA)  nodeA = headB;
            if(!nodeB)  nodeB = headA;
            if(nodeA == nodeB)  return nodeA;
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        
        return NULL;
    }
};