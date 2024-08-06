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
    bool isCompleteTree(TreeNode* root) {
        int nodeCount = 0;
        NC(root,nodeCount);
        cout<<nodeCount<<" ";
        bool res = CT(root,0,nodeCount);
        return res;
    }
    void NC(TreeNode* root, int &Nc){
            if(!root)
            return;
            Nc++;
            NC(root->left,Nc);
            NC(root->right,Nc);
        }
    bool CT(TreeNode* root, int i, int nodeCount){
            if(!root)
            return true;
            if(i >= nodeCount)
            return false;
            cout<<i<<" ";
            bool left = CT(root->left, 2*i+1, nodeCount);
            bool right = CT(root->right, 2*i+2, nodeCount);
            return left&&right;
        }
};