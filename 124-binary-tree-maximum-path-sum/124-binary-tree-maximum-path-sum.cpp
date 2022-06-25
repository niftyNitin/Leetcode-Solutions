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
    int findMaxSum(TreeNode* root, int &max_sum) {
        if(root == NULL)    return 0;
            
        int left_sum = findMaxSum(root->left, max_sum);
        if(left_sum < 0)    left_sum = 0;
        int right_sum = findMaxSum(root->right, max_sum);
        if(right_sum < 0)   right_sum = 0;
        int total_sum = root->val + left_sum + right_sum;
        if(total_sum > max_sum) max_sum = total_sum;
        return root->val + max(left_sum, right_sum);
    }
    
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        findMaxSum(root, max_sum);
        return max_sum;
    }
};