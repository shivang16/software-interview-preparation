class Solution {
public:
    vector <int> buildKmp(string s){
        int n = s.size();
        vector <int> table(n,0);
        int j=0,i=1;
        while(i<n){
            j = table[i-1];
            while(j>0 && s[i]!=s[j])
                j = table[j-1];
            if(s[i]==s[j])
                j++;
            table[i] = j;
            i++;
        }
        return table;
    }
    string shortestPalindrome(string s) {
        string ns = s;
        reverse(ns.begin(),ns.end());
        string fs = s+a'#'+ns;
        vector <int> table = buildKmp(fs);
        return ns.substr(0,s.size()-table[fs.size()-1])+s;
    }
};