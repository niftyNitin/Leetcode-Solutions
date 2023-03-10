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
    int n = 0;
    vector<int> v;
    Solution(ListNode* head) {
        ListNode* temp = head;
        while(temp) {
            ++n;
            v.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    int getRandom() {
        int p = 1 + (rand() % (n));
        return v[p-1];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */