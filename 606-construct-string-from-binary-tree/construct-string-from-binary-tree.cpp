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
    
    void makeString(TreeNode* root,string &ans){
        if(!root){
            return;
        }
        string curr = to_string(root->val);
        ans+=(curr);
        if(root->left||root->right)
        {ans.push_back('(');
        makeString(root->left,ans);
        ans.push_back(')');}
        if(root->right)
        {ans.push_back('(');
        makeString(root->right,ans);
        ans.push_back(')');}

    }
    string tree2str(TreeNode* root) {
        string ans="";
        makeString(root,ans);
        return ans;
    }
};