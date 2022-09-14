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
    int dfs(TreeNode* root, unordered_map<int,int> &mp) {
        if(!root)   return 0;
        mp[root->val]++;
        if(!root->left and !root->right) {
            int odd = 0;
            for(auto i : mp) {
                if(i.second % 2 != 0)   odd++;
            }
            mp[root->val]--;
            if(odd <= 1)    return 1;
            else    return 0;
        }
        
        int left = dfs(root->left, mp);
        int right = dfs(root->right, mp);
        mp[root->val]--;
        return left + right;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        return dfs(root, mp);
    }
};