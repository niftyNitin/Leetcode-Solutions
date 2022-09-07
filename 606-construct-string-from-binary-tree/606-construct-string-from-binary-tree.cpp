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
    string tree2str(TreeNode* root) {
        if(!root)   return "";
        string s = "";
        s += to_string(root->val);
        string a = "", b = "";
        if(root->left) {
            a = tree2str(root->left);
        }
        if(root->right){
            b = tree2str(root->right);
        }
        
        if(a != "" and b != "") {
            s += "(" + a + ")";
            s += "(" + b + ")";
        }
        else if(a == "" and b != "") {
            s += "()(" + b + ")";
        }
        else if(a != "" and b == "") {
            s += "(" + a + ")";
        }
        return s;
    }
};