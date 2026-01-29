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
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int l = rec(root->left);
        int r = rec(root->right);
        abs(l-r) > 1 ? ans = false : ans;
        return ans;
    }
    int rec(TreeNode* root){
        if(!root) return 0;
        int l= rec(root->left);
        int r = rec(root->right);
        abs(l-r) > 1 ? ans = false : ans;
        return 1+max(l, r);
    }
};