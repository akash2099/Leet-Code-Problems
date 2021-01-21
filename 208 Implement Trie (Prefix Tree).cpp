class TrieNode {
public:
    TrieNode(bool b = false){
        is_word = b;
        memset(next, 0, sizeof(next)); // 0 is equivalent to nullptr
    }
    TrieNode  *next[26];
    bool is_word;
};


class Trie {
private:
    TrieNode *root;
    
    TrieNode *find_string(std::string word){
        auto temp = root;
        for(int i = 0; i < word.size(); i++){
            if(temp->next[word[i] - 'a'] != nullptr)
                temp = temp -> next[word[i] - 'a'];
            else {
                temp = nullptr;
                break;
            }
        }
        return temp;
    }
    
    void clear(TrieNode *root){ // recursively delete each node ptr
        for(int i = 0; i < 26; i++){
            if(root->next[i] != nullptr){
                clear(root->next[i]);
            }
        }
        delete root;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
         root = new TrieNode;
    }
    
    ~Trie(){
        clear(root);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto temp = root;
        for(int i = 0; i < word.size(); i++){
            if(temp->next[word[i] - 'a'] == nullptr)
                temp->next[word[i] - 'a'] = new TrieNode;
            temp = temp->next[word[i]-'a'];
        }
        temp->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto temp = find_string(word);
        if(temp != nullptr && (temp->is_word))
            return true;
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto temp = find_string(prefix);
        if(temp != nullptr) // here is_word is not checked because its prefix
            return true;
        else
            return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
