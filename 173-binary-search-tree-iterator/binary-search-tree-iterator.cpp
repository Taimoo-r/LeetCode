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
class BSTIterator {
public:
    vector<int> v;
    int s = 0;
    int i = 0;
    BSTIterator(TreeNode* root) {
        in(root);
        s = v.size()-1;
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        if(i > s) return false;
        else return true;
    }
    
    void in(TreeNode* root){
        if(!root) return;

        in(root->left);
        v.push_back(root->val);
        in(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */