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
    int result;
    void solve(TreeNode* root, int maxx, int mini) {
        if(!root)   return;
        int currRes = max(abs(maxx-root->val), abs(mini-root->val));
        result = max(result, currRes);
        maxx = max(maxx, root->val);
        mini = min(mini, root->val);
        
        solve(root->left, maxx, mini);
        solve(root->right, maxx, mini);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root)   return 0;
        result = 0;
        solve(root, root->val, root->val);
        return result;
    }
};