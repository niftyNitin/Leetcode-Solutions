class Solution {
public:
    bool check(TreeNode* root, TreeNode* subRoot) {
        if(!root and !subRoot)    return true;
        if(!root or !subRoot)    return false;
        if(root->val != subRoot->val)    return false;
        return check(root->left, subRoot->left) and check(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)   return false;
        if (check(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};