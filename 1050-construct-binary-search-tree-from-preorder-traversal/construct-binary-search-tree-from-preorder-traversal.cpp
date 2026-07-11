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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root = new TreeNode(pre[0]);
        for(int i = 1; i < pre.size() ; i++){
            rec(pre[i], root);
        }
        return root;
    }
    void rec(int val, TreeNode* root){
        if(val < root->val){
            if(root->left) rec(val, root->left);
            else {
                root->left = new TreeNode(val); return;
            }
        }
        if(val > root->val){
            if(root->right) rec(val, root->right);
            else {
                root->right = new TreeNode(val); return;
            }
        }
    }
};