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
    bool solve(TreeNode* left, TreeNode* right) {
        if(!left and !right)    return 1;
        if(!left or !right)     return 0;
        if(left->val != right->val) return 0;
        return solve(left->right, right->left) and solve(left->left, right->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        return solve(root->left, root->right);
    }
};