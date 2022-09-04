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
    void solve(TreeNode* root, long long targetSum, int &c) {
        if(!root)   return;
        if(targetSum == root->val) {
            ++c;     
        }
        
        solve(root->left, targetSum - root->val, c);
        solve(root->right, targetSum - root->val, c);
    }
    
    void dfs(TreeNode* root, int targetSum, int &count) {
        int c = 0;
        solve(root, targetSum, c);
        count += c;
        if(root->left)  dfs(root->left, targetSum, count);
        if(root->right) dfs(root->right, targetSum, count);
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)   return 0;
        int count = 0;
        dfs(root, targetSum, count);
        return count;
    }
};