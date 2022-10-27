class Solution {
public:
    bool checker(string s,string t){
        bool vis = false;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]){
                if(vis)
                    return false;
                vis = true;
            }
        }
        return vis;
    }
    int helper(string s,string t){
        int l = s.length();
        int ans = 0;
        for(int i=0;i<=t.length()-l;i++){
            string str = t.substr(i,l);
            if(checker(s,str)){
                // cout << s << " " << str << endl;
                
                ans++;
            }
        }
        return ans;
    }
    int countSubstrings(string s, string t) {
        int ans = 0;
        for(int l=1;l<=s.length();l++){
            for(int i=0;i<=s.length()-l;i++){
                string str = s.substr(i,l);
                if(str.length()<=t.length()){
                    ans+=helper(str,t);
                }
            }
        }
        return ans;
    }
};