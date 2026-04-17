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
    int maxi = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        rec(root);
        return maxi;
        // here basically we're returning the sum of max depth of left & right.
    }
    int rec(TreeNode* root){
        if(!root) return 0;
        int l = rec(root->left);
        int r = rec(root->right);
        maxi = max(maxi, l+r);
        return max(l, r)+1;
    }
};