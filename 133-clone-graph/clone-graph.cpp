/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
        return node;
        unordered_map<int, Node *> mp;
        set<int> vis;
        Node* copy = new Node(node->val);
        mp[node->val] = copy;
        dfs(node, copy, vis, mp);
        return copy;
    }
    void dfs(Node* node, Node* copy, set<int> &vis, unordered_map<int, Node *>& mp){
        vis.insert(copy->val);
        for(auto neighbor : node->neighbors){
            if(!vis.count(neighbor->val)){
                Node* nei = new Node(neighbor->val);
                mp[neighbor->val] = nei;
                copy->neighbors.push_back(nei);
                dfs(neighbor,nei, vis, mp);
            }
            else{
                copy->neighbors.push_back(mp[neighbor->val]);
            }
        }
    }
};