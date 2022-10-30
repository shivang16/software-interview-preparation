class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack <int> S;
        unordered_map <char,int> freq;
        unordered_map <char,bool> vis;
        for(auto i:s){
            freq[i]++;
        }
        string ans = "";
        for(int i=0;i<s.length();i++){
            freq[s[i]]--;
            if(vis[s[i]]) continue;
            
            while(!S.empty() && s[i]<=s[S.top()] && freq[s[S.top()]]>0){
                vis[s[S.top()]] = false; 
                S.pop();
            }
            S.push(i);
            vis[s[i]] = true;
            
        }
        while(!S.empty()){
            ans = s[S.top()]+ans;
            S.pop();
        }
        return ans;
    }
};