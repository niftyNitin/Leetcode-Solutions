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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q)   return 1;
        if(!p or !q)    return 0;
        
        if(p->val != q->val) return 0;
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot)  return true;
        if(!root or !subRoot)   return false;
        if(root->val == subRoot->val and isSameTree(root->left, subRoot->left) and isSameTree(root->right, subRoot->right))
            return true;
        
        bool a = isSubtree(root->left, subRoot);
        bool b = isSubtree(root->right, subRoot);
        
        return a+b;
    }
};