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
    int idx = 0;
    TreeNode* rec(vector<int>& pre, vector<int>& in, int st, int en){
        if(st > en) return nullptr;
        TreeNode* root = new TreeNode(pre[idx]);

        int j = 0;
        for(j = st; j <= en ; j++){
            if(in[j]==pre[idx]) break;
        }
        idx++;
        root->left = rec(pre, in, st, j-1);
        root->right = rec(pre, in, j+1, en);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return rec(preorder, inorder, 0, preorder.size()-1);
    }
};