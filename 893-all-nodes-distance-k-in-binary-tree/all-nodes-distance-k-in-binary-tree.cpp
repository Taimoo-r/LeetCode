class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();

            if(node->left){
                adj[node].push_back(node->left);
                adj[node->left].push_back(node);
                q.push(node->left);
            }

            if(node->right){
                adj[node].push_back(node->right);
                adj[node->right].push_back(node);
                q.push(node->right);
            }
        }
        queue<TreeNode*> bfs;
        unordered_set<TreeNode*> vis;
        bfs.push(target);
        vis.insert(target);
        int dis = 0;
        while(!bfs.empty()){
            int sz = bfs.size();

            if(dis == k){
                vector<int> ans;
                while(!bfs.empty()){
                    ans.push_back(bfs.front()->val);
                    bfs.pop();
                }
                return ans;
            }
            while(sz--){
                TreeNode* node = bfs.front(); bfs.pop();
                for(auto &x : adj[node]){
                    if(!vis.count(x)){
                        vis.insert(x);
                        bfs.push(x);
                    }
                }
            }
            dis++;
        }
        return {};
    }
};