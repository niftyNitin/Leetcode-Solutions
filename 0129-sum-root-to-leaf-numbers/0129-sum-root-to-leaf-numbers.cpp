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
    int ans = 0;
    void solve(TreeNode* root, int sum) {
        if(!root->left and !root->right) {
            sum = sum*10 + root->val;
            ans += sum;
            return;
        }
        
        sum = sum*10 + root->val;
        if(root->left)  solve(root->left, sum);
        if(root->right) solve(root->right, sum);
    }
    
public:
    int sumNumbers(TreeNode* root) {
        if(!root)   return 0;
        solve(root, 0);
        return ans;
    }
};