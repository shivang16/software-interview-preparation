// https://leetcode.com/problems/longest-word-in-dictionary/
class TrieNode{
    unordered_map <char,TrieNode*> child;
    bool isEnd;
    TrieNode(){
        isEnd = false;
    }

    void insert(TrieNode* root,string s){
        TrieNode* temp = root;
        for(auto i:s){
            if(temp->child[i]==temp->child.end())
                temp->child[i] = new TrieNode();
            temp = temp->child[i];
        }
        temp->isEnd = true;
    }

    bool search(TrieNode* root,string s){
        TrieNode* temp = root;
        for(auto i:s){
            if(temp->child[i]==temp->child.end())
                return false;
            temp = temp->child[i];
        }
        return temp->isEnd;
    }
};
class Solution {
public:

    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        vector <bool> ans
        for(auto )
    }
};