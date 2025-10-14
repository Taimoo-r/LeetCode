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
        if(!node) return nullptr;

        unordered_map<int, Node*> mp;
        Node* copy = new Node(node->val);
        // mp[node->val] = copy;

        dfs(node, copy, mp); 
        return copy;
    }
    void dfs(Node* node, Node* copy, unordered_map<int, Node*>& mp){
        mp[copy->val] = copy;
        for(auto &n : node->neighbors){
            if(!mp.count(n->val)){
                Node* c = new Node(n->val);
                copy->neighbors.push_back(c);
                dfs(n, c, mp);
            } else {
                copy->neighbors.push_back(mp[n->val]);
            }
        }
    }
};