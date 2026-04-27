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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        ll maxi = 0;
        while(!q.empty()){
            int sz= q.size();
            auto [nodel, idxl] = q.front();
            auto [noder, idxr] = q.back();
            maxi = max(maxi, idxr-idxl+1);
            while(sz){
                auto [node, idx] = q.front(); q.pop();
                // cout<<node<<" "<<idx<<endl;
                if(node->left) q.push({node->left, idx*2+1});
                if(node->right) q.push({node->right, idx*2+2});
                sz--;
            }
        }
        return maxi;
    }
};