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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)   return {};
        vector<string> res;
        helper(root, res, "");
        return res;
    }
    
    void helper(TreeNode* root, vector<string> &res, string path) {
        path = path + to_string(root->val) + "->";
        if(root->left)  helper(root->left, res, path);
        if(root->right) helper(root->right, res, path);
        if(!root->left and !root->right) {
            path.pop_back();
            path.pop_back();
            res.push_back(path);
        }
    }
};