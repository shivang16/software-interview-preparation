class TrieNode{
    public: 
        TrieNode* child[26];
        bool end;
        TrieNode(){
            memset(child,NULL,sizeof(child));
            end = false;
        }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            int ind = c-'a';
            if(temp->child[ind]==NULL){
                temp->child[ind] = new TrieNode();
            }
            temp = temp->child[ind];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            int ind = c-'a';
            if(temp->child[ind]==NULL){
                return false;
            }
            temp = temp->child[ind];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i=0;i<prefix.size();i++){
            char c = prefix[i];
            int ind = c-'a';
            if(temp->child[ind]==NULL){
                return false;
            }
            temp = temp->child[ind];
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