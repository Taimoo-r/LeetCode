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
    priority_queue<int> pq; 
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* top = q.front(); q.pop();
            pq.push(top->val);
            
            if(pq.size() > k){
                pq.pop();
            }
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        return pq.top();
    }
};