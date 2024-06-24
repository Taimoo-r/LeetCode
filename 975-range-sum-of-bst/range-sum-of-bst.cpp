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
    static int sum;

    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0; // Reset sum before starting the calculation
        rangeSumBSTHelper(root, low, high);
        return sum;
    }

private:
    void rangeSumBSTHelper(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= low) {
            rangeSumBSTHelper(root->left, low, high);
        }

        if (root->val >= low && root->val <= high) {
            sum += root->val;
            cout << root->val << " ";
        }

        if (root->val <= high) {
            rangeSumBSTHelper(root->right, low, high);
        }
    }
};
int Solution::sum = 0;

