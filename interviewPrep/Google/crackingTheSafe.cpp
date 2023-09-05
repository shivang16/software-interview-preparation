// https://leetcode.com/problems/cracking-the-safe/description/
class Solution {
public:

    void dfs(int k,int n,unordered_set <string> &vis,string &ans,string temp){
        for(int i=0;i<k;i++){
            string s = temp+to_string(i);
            if(!vis.count(s)){
                vis.insert(s);
                dfs(k,n,vis,ans,s.substr(1));
                ans+=to_string(i);
            }
        }
    }
    string crackSafe(int n, int k) {
        string ans = "",temp = "";
        unordered_set <string> vis;
        for(int i=0;i<n-1;i++){
            temp+="0";
        }
        dfs(k,n,vis,ans,temp);
        return ans+temp;
    }

};