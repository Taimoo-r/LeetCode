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
    bool isValidBST(TreeNode* root) {
        if(!root)
        return true;
        return height(root,LONG_MIN,LONG_MAX);
        
    }
    bool height(TreeNode *r, long min, long max){
        if(!r)
        return true;
        if(r->val <=min || r->val >= max)
        return false;
        return height(r->left, min, r->val) && height(r->right, r->val, max);

    }
};