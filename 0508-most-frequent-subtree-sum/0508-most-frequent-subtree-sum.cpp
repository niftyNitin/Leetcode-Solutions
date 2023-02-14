/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    int solve(TreeNode* root) {
        if(!root)   return 0;
        int sum = root->val + solve(root->left) + solve(root->right);
        mp[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        vector<int> ans;
        map<int,vector<int>> rev;
        for(auto i : mp) {
            rev[i.second].push_back(i.first);
        }
        return rev.rbegin()->second;
    }
};