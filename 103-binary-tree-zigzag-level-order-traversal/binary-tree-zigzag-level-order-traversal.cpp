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
 #include <deque>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        deque<TreeNode*> dq;
        dq.push_front(root);
        int k = 0;
        vector<vector<int>> v;
        while(!dq.empty()){
            int n = dq.size();

            vector<int> c;
            for(int i = 0 ; i < n ; i++){
                TreeNode* node;
                node = dq.front(); dq.pop_front();
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
                c.push_back(node->val);
            }
            if(k&1) reverse(begin(c), end(c));
            k++;
            v.push_back(c);
        }
        return v;
    }
};