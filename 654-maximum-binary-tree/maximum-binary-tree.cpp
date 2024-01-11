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
    TreeNode* getTree(int i,int j,vector<int>&nums){
        if(i>j)return NULL;
        if(i==j){
            TreeNode* root=new TreeNode(nums[i]);
            return root;
        }
        int maxi=INT_MIN,maxIdx;
        for(int k=i;k<=j;k++){
            if(maxi<nums[k]){
                maxIdx=k;
                maxi=nums[k];
            }
        }
        TreeNode* root=new TreeNode(maxi);
        root->left=getTree(i,maxIdx-1,nums);
        root->right=getTree(maxIdx+1,j,nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return getTree(0,nums.size()-1,nums);
    }
};