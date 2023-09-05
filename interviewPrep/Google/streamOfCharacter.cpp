// https://leetcode.com/problems/stream-of-characters/
class TrieNode{
    public:
        unordered_map <char,TrieNode*> child;
        bool isEnd;

        TrieNode(){
            isEnd = false;
        }

        void insert(string s){
            TrieNode* temp = this;
            for(auto i:s){
                if(temp->child.find(i)==temp->child.end())
                    temp->child[i] = new TrieNode();
                temp = temp->child[i];
            }
            temp->isEnd = true;
        }

        bool search(string s){
            TrieNode* temp = this;
            for(auto i:s){
                if(temp->isEnd) return true;
                if(temp->child.find(i)==temp->child.end())
                    return false;
                temp = temp->child[i];
            }
            return temp->isEnd;
        }


};

class StreamChecker {
public:

    TrieNode* root;
    string crntString;
    int maxLength;

    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        maxLength = 0;
        crntString = "";
        for(auto i:words){
            int sz = i.size();
            maxLength = max(maxLength,sz);
            string s = i;
            reverse(s.begin(),s.end());
            root->insert(s);
        }
    }
    
    bool query(char letter) {
        crntString = letter+crntString;
        if(crntString.size() > maxLength){
            crntString.pop_back();
        }
        return root->search(crntString);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */