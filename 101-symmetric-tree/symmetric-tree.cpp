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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            while(n){
                TreeNode* node = q.front(); q.pop();
                if(node->left) {
                    q.push(node->left);
                    v.push_back(node->left->val);
                }else v.push_back(-101);
                if(node->right){
                    v.push_back(node->right->val);
                    q.push(node->right);
                } else v.push_back(-101);
                n--;
            }
            if(v.size()%2!=0) return false;
            // reverse(v.begin()+v.size()/2, v.end());
            for(auto &x : v) cout<<x<<" ";
            cout<<endl;
            int i = 0, j = v.size()-1;
            while(i <= j){
                if(v[i]!=v[j]) return false;
                i++, j--;
            }
        }
        return true;
    }
};