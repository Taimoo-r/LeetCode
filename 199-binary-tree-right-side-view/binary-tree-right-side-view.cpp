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
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        unordered_set<int> s;
        vector<int> ans;
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int lev = st.top().second;
            st.pop();
            if(!s.count(lev)) ans.push_back(node->val);
            s.insert(lev);
            if(node->left) st.push({node->left, lev+1});
            if(node->right) st.push({node->right, lev+1});
        }
        return ans;
    }
};