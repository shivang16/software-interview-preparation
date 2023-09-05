// https://leetcode.com/problems/extra-characters-in-a-string/description/
class TrieNode{
    private: 
        unordered_map <char,TrieNode*> child;
        bool isEnd;
    public:
        TrieNode(){
            isEnd = false;
        }

        void insert(string s){
            TrieNode* temp = this;
            for(auto i:s){
                if(temp->child.count(i)==0)
                    temp->child[i] = new TrieNode();
                temp = temp->child[i];
            }
            temp->isEnd = true;
        }

        int search(string s){
            int n = s.size();
            vector <int> dp(n+1,0);
            for(int i=n-1;i>=0;i--){
                dp[i] = dp[i+1]+1;
                TrieNode* temp = this;
                for(int j=i;j<n;j++){
                    if(temp->child.count(s[j])==0){
                        break;
                    }
                    temp = temp->child[s[j]];
                    if(temp->isEnd){
                        dp[i] = min(dp[i],dp[j+1]);
                    }
                }
            }
            return dp[0];
        }
};
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode* root = new TrieNode();
        for(auto i:dictionary)
            root->insert(i);
        return root->search(s);
    }
};