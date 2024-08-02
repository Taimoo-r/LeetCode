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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        hasPathSum(root, targetSum,ans);
        return ans; 
    }
    void hasPathSum(TreeNode *root, int t, bool &ans){
        if(!root)
        return;
        if(ans)
        return;
        t-=root->val;
        hasPathSum(root->left,t,ans);
        if(!root->left && !root->right && t==0)
        ans = true;
        hasPathSum(root->right,t, ans);
        return;


    }
};