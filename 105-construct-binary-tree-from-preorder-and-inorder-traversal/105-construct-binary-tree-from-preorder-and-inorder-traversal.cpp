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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, 0, inorder.size()-1, preorder, inorder);
    }
                      
    TreeNode* helper(int prestart, int instart, int inend, vector<int> &preorder, vector<int> &inorder) {
        if(prestart > preorder.size()-1 or instart > inend)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inidx = 0;
        for(int i = instart; i <= inend; i++) {
            if(inorder[i] == root->val)
                inidx = i;
        }
        
        root->left = helper(prestart+1, instart, inidx-1, preorder, inorder);
        root->right = helper(prestart+inidx-instart+1, inidx+1, inend, preorder, inorder);
        return root;
    }
};