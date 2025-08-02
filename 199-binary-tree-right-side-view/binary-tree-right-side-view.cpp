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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        map<int, int> mp;
        mp[0] = root->val;
        while(!q.empty()){
            pair<TreeNode*,int> top = q.front();
            q.pop();
            if(top.first->left){
                q.push({top.first->left, top.second+1});
                mp[top.second+1] = top.first->left->val;
            } 
            if(top.first->right){
                q.push({top.first->right, top.second+1});
                mp[top.second+1] = top.first->right->val;
            } 
        }
        for(auto &[a,it] : mp) ans.push_back(it);
        return ans;
    }
};