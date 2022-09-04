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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>> mp;
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int lvl = 0;
        while(!q.empty()) {
            int k = q.size();
            while(k--) {
                auto [node, idx] = q.front();
                q.pop();
                mp[idx][lvl].insert(node->val);
                if(node->left) {
                    q.push({node->left, idx-1});
                }
                if(node->right) {
                    q.push({node->right, idx+1});
                }
            }
            lvl++;
        }
        
        for(auto i : mp) {
            vector<int> temp;
            for(auto j : i.second)
                for(auto s : j.second)
                    temp.push_back(s);
            
            ans.push_back(temp);
        }
        return ans;
    }
};