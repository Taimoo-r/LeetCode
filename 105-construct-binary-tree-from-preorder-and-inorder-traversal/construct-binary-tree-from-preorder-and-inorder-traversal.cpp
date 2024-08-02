
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1, inorder, mp);
    }

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, int inStart, int inEnd, vector<int>& inorder, map<int, int>& mp) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inStart, inRoot - 1, inorder, mp);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd, inorder, mp);

        return root;
    }
};
