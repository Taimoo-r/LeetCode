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
    int maxi = -1001;
    int maxPathSum(TreeNode* root) {
        rec(root);
        return maxi;
    }
    int rec(TreeNode* root){
        if(!root) return 0;
        int l = rec(root->left);
        int r = rec(root->right);
        int val = root->val;
        if(l < 0) l = 0;
        if(r < 0) r = 0;
        maxi = max(maxi, val+l+r);
        // cout<<val+l+r<<endl;
        return root->val + max(l, r);
    }
};