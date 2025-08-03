class Solution {
public:
    TreeNode* prev = nullptr;

    bool helper(TreeNode* root) {
        if (!root) return true;

        if (!helper(root->left)) return false;

        if (prev && prev->val >= root->val) return false;
        prev = root;

        return helper(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
};
