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
    TreeNode *FindMin(TreeNode* root){
        if(root==nullptr)
        return nullptr;
        while(root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root!=nullptr && key > root->val)
        root->right = deleteNode(root->right,key);
        else if(root!=nullptr && key <  root->val)
        root->left = deleteNode(root->left,key);
        else{
            if(root!=nullptr && root->left==nullptr && root->right==nullptr){
                delete root;
                root = nullptr;
            }
            else if(root!=nullptr && root->left==nullptr){
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root!=nullptr && root->right==nullptr){
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            else{
                TreeNode *temp;
                if(root!=nullptr){
                temp =  FindMin(root->right);
                root->val = temp->val;}
                else
                return nullptr;
                root->right = deleteNode(root->right,temp->val);
            }
            
        }
        return root;
    }
};