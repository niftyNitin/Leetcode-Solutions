/**
 * Definition for a binary tree node.
 * mpruct TreeNode {
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
    void setInsertion(TreeNode* root, unordered_map<int, TreeNode*> &mp) {
        if(!root)   return;
        mp[root->val] = root;
        setInsertion(root->left, mp);
        setInsertion(root->right, mp);
    }
    
    bool findSum(TreeNode* root, int &k, unordered_map<int, TreeNode*> &mp) {
        if(!root)   return 0;
        if(mp.count(k-root->val) and mp[root->val] != mp[k-root->val])
            return 1;
        return findSum(root->left, k, mp) or findSum(root->right, k, mp);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, TreeNode*> mp;
        setInsertion(root, mp);
        return findSum(root, k, mp);
    }
};