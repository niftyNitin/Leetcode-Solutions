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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root)   return {};
        q.push(root);
        int flag = 0;
        while(!q.empty()) {
            flag = flag ^ 1;
            int n = q.size();
            vector<int> v;
            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->right) q.push(temp->right);
                if(temp->left)  q.push(temp->left);
                v.push_back(temp->val);
            }
            if(flag == 0)
                ans.push_back(v);
            else{
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
        }
        return ans;
    }
};