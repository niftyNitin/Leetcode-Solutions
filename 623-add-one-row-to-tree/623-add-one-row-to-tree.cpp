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
    void dfs(TreeNode* root, int val, int depth, int depthNow) {
        if(!root)   return;
        if(depthNow == depth-1) {
            TreeNode* tempLeft = root->left;
            TreeNode* tempRight = root->right;
            
            TreeNode* left = new TreeNode(val, tempLeft, NULL);
            TreeNode* right = new TreeNode(val, NULL, tempRight);
            root->left = left;
            root->right = right;
            return;
        }
        
        dfs(root->left, val, depth, depthNow+1);
        dfs(root->right, val, depth, depthNow+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)  {
            TreeNode* nroot = new TreeNode(val, root, NULL);
            return nroot;
        }
        
        dfs(root, val, depth, 1);
        return root;
    }
};