class Solution {
public:
    vector<TreeNode*> nodes;

    void dfs(TreeNode* root){
        if(!root) return;

        nodes.push_back(root);

        dfs(root->left);
        dfs(root->right);
    }

    void flatten(TreeNode* root) {
        dfs(root);

        for(int i = 0; i + 1 < nodes.size(); i++){
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }

        if(!nodes.empty()){
            nodes.back()->left = nullptr;
            nodes.back()->right = nullptr;
        }
    }
};