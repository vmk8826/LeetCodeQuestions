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
    void inOrder(TreeNode* node,vector<int>&ret){
       stack<TreeNode*>st;
        // st.push(node);
        while(true){
            
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                // cout<<st.top()->val;
                if(st.empty())break;
                ret.push_back(st.top()->val);
                node=st.top();
                st.pop();
                node=node->right;
            }
        }     
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        inOrder(root,ret);
        return ret;
    }
};