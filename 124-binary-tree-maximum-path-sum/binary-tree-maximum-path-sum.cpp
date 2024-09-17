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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        findSum(root, maxSum);
        return maxSum;
    }
    int findSum(TreeNode* root, int& maxSum){
        if(!root)
            return 0;
        int l = max(findSum(root->left ,maxSum),0);
        int r = max(findSum(root->right ,maxSum),0);
        maxSum = max(maxSum, l + r + root->val);
        return max(l, r) + root->val;
    }
};