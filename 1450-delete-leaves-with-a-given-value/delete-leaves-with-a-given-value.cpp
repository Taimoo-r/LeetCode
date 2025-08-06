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
    TreeNode* help(TreeNode* root, int t){
        if(!root) return nullptr;

        root->left = help(root->left, t);
        root->right = help(root->right, t);

        if(!root->left && !root->right && root->val == t) return nullptr;
        else return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        return help(root, t);
    }
};