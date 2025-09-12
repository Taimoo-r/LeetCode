class TrieNode{
    public:
    TrieNode *arr[26]{};
    bool isEnd = false;
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return help(word, 0, root);
    }

    bool help(string& word, int i, TrieNode* node){
        if(i >= word.size() && node->isEnd) return true;
        if(i >= word.size()) return false;
        if(word[i]=='.'){
            for(int j = 0 ; j < 26 ; j++){
                if(node->arr[j] != nullptr){
                    if(help(word, i+1, node->arr[j]))
                        return true;
                }
            }
            return false;
        }
        int idx = word[i] - 'a';
        if(node->arr[idx] == nullptr) return false;

        return help(word, i+1, node->arr[idx]);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */