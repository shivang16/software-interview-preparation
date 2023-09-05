// https://leetcode.com/problems/rearrange-spaces-between-words
class Solution {
public:
    vector <string> split(string text,string del){
        vector <string> ans;
        char* token = strtok(&text[0],&del[0]);
        while(token){
            ans.push_back(token);
            token = strtok(NULL,&del[0]);
        }
        return ans;
    }
    string reorderSpaces(string text) {
        vector <string> words = split(text," ");
        int sz = 0;
        for(auto i:words){
            sz+=i.size();
        }
        int totalSpaces = text.size()-sz;
        if(totalSpaces==0)
            return text;
        int totalWords = words.size();
        int spaces;
        if(totalWords>1)
            spaces = totalSpaces/(totalWords-1);
        else
            spaces = totalSpaces;
        // cout << totalSpaces << " " << totalWords << " " << spaces << endl;
        string ans = "";
        for(auto i:words){
            ans+=i;
            int j = spaces;
            while(j-->0 && totalSpaces-->0){
                ans+=' ';
            }
        }
        while(totalSpaces-->0)
            ans+=' ';
        return ans;
        
    }
};