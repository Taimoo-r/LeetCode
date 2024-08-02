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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vec;
        vector<vector<int>> v2; 
        hasPathSum(root, targetSum, vec, v2);
        return v2;
    }
    void hasPathSum(TreeNode *root, int t,vector<int> &v,vector<vector<int>> &v2){
        if(!root)
        return;
        t-=root->val;
        v.push_back(root->val);
        if(!root->left && !root->right && t==0){
        v2.push_back(v);
        }
        hasPathSum(root->left,t,v,v2);
        hasPathSum(root->right,t,v, v2);
        v.pop_back();
    }
};