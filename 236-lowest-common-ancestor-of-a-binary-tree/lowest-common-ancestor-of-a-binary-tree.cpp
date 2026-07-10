/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ret;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rec(root, p, q);
        return ret;
    }
    bool rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root|| ret) return false;
        bool l = rec(root->left, p, q);
        bool r = rec(root->right, p, q);

        if(l&&r) ret = root;
        if((l || r) && (root==p || root==q)) ret = root;
        if(l || r || root ==p || root == q) return true;
        return false;


    }
};