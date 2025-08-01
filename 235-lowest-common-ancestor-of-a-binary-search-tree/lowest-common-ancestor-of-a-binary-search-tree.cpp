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
    TreeNode* lowestCommonAncestor(TreeNode* curr, TreeNode* p, TreeNode* q) {
        while(curr){
            if(curr->val > p->val  && curr->val > q->val){
                curr = curr->left;
            } else if(curr->val < p->val && curr->val < q->val)
                curr = curr->right;
            else return curr;
        }
        return nullptr;
    }
};