class Solution {
public:
    bool isPalindrom(string s,int st,int ed){
        while(ed>st){
            if(s[st++]!=s[ed--])
                return false;
        }
        return true;
    }
    void backtrack(string s,vector <vector <string>> &ans,vector <string> &temp,int ind){
        if(ind==s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.length();i++){
            if(isPalindrom(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                backtrack(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector <vector <string>> ans;
        vector <string> temp;
        backtrack(s,ans,temp,0);

        return ans;
    }
};


// abaeccce
// 