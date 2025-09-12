class TrieNode{
    public:
    TrieNode *arr[26]{};
    bool isEnd = false;
};
class Trie{
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;

        for(auto &c : word){
            int i = c - 'a';
            if(node->arr[i] == nullptr){
                node->arr[i] = new TrieNode();
            }
            node = node->arr[i];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;

        for(auto &c : word){
            int i = c - 'a';
            if(node->arr[i] == nullptr) return false;
            node = node->arr[i];
        }

        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;

        for(auto &c : prefix){
            int i = c - 'a';
            if(node->arr[i] == nullptr) return false;
            node = node->arr[i];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */