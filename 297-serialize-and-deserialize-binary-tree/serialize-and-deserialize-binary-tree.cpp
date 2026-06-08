/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    // Encodes a tree to a single string.
    #include<string>
class Codec{
public:
    int i = 0;
    string s = "";
    string serialize(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* top = q.front(); q.pop();
            if(top==nullptr){
                s+="N&";
            } else {
                s = s+to_string(top->val)+"&";
                if(top->left) q.push(top->left);
                else q.push(nullptr);
                if(top->right) q.push(top->right);
                else q.push(nullptr);
            }
        }
        return s;
    }

    int getN(){
        string n = "";
        if(s[i]=='N') {
            i+=2;
            return 1001;
        }
        for(i ; i < s.size() ; i++){
            if(s[i]=='&'){
                i++;
                break;
            }
            n+=s[i];
        }
        return std::stoi(n);
    }
    // Decodes your encoded dazta to tree.
    TreeNode* deserialize(string data){
        s = data;
        queue<TreeNode*> q;
        int rot = getN();
        if(rot == 1001) return nullptr;
        TreeNode* root = new TreeNode(rot);
        q.push(root);
        while(!q.empty()){
            TreeNode* top = q.front(); q.pop();
            int l = getN();
            int r = getN();
            if(l != 1001){
                top->left = new TreeNode(l);
                q.push(top->left);
            }
            if(r != 1001){
                top->right = new TreeNode(r);
                q.push(top->right);
            }
        }
        i = 0;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));