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
    bool searchBST(TreeNode* curr, int diff, TreeNode* root) {
        if(!root)   return false;
        if(root->val == diff and curr != root)   return true;
        if(diff < root->val)    return searchBST(curr, diff, root->left);
        else    return searchBST(curr, diff, root->right);
    }
    
    bool findTargetHelper(TreeNode* curr, int k, TreeNode* root) {
        if(!curr)   return false;
        if(searchBST(curr, k-curr->val, root))    return true;
        return findTargetHelper(curr->left, k, root) or findTargetHelper(curr->right, k, root);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(!root)   return false;
        return findTargetHelper(root, k, root);
    }
};