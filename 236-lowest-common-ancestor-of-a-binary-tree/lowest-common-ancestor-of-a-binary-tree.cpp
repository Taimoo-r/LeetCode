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
    TreeNode* ans = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root == p || root == q) return root;
        // rec(root->left, p, q);
        // if(P && Q && first !=-1) return first ? q : p;
        // if(first == -1) { 
        //     rec(root->right, p, q);
        //     return first ? q : p;
        // }
        // else return root;
        rec(root, p, q);
        return ans;
        
    }
    bool rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || ans) return false;
        bool l = rec(root->left, p, q);
        bool r = rec(root->right, p, q);
        if(l && r) ans = root;
        if((l || r) && (root == p || root == q)) ans = root;
        if(root == p || root == q || l || r) return true;
        return false;


        // if(root == p){
        //     P = true;
        //     if(!Q) first = 0;
        // }
        // if(root == q){
        //     Q = true;
        //     if(!P) first = 1;
        // }
        // if(!P || !Q){
        //     rec(root->left, p, q);
        //     rec(root->right, p, q);
        // }
    }
};