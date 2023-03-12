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
    ListNode* mergeList(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        while(head1 and head2) {
            if(head1->val < head2->val) {
                tail->next = head1;
                tail = tail->next;
                head1 = head1->next;
            } else {
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
            }
        }
        
        while(head1) {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
        }
        while(head2) {
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
        
        return dummy->next;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)   return NULL;
        int start = 0, end = lists.size()-1;
        while(end > 0) {
            start = 0;
            while(start < end) {
                lists[start] = mergeList(lists[start], lists[end]);
                start++;
                end--;
            }
        }
        return lists[0];
    }
};