/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < n; i++) {
            insert(preorder[i], root);
        }
        return root;
    }


    TreeNode* insert(int val, TreeNode* root) {
        if (!root) {
            return new TreeNode(val);
        }
        if (val < root->val) {
            root->left = insert(val, root->left);
        } else {
            root->right = insert(val, root->right);
        }
        return root;
    }
};
