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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int s = 0;
        return sum(root,low,high,&s);
        
    }
    int sum(TreeNode* root, int l, int h, int *s){
        if(!root)
        return 0;
        if(root->val >=l && root->val <=h)
        *s+=root->val;
        sum(root->left,l,h,s);
        sum(root->right,l,h,s);
        return *s;
    }
};