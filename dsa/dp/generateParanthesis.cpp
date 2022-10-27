class Solution {
public:
    bool isValid(string s){
        stack <char> S;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                S.push('(');
            }else{
                if(S.empty())
                    return false;
                S.pop();
            }
        }
        return S.empty();
    }
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        ans.push_back("()");
        for(int i=1;i<n;i++){
            int sz = ans.size();
            for(int j=0;j<sz;j++){
                string s = ans[j];
                // cout << i << " " << j << " " <<s << endl;
                for(int k=0;k<s.length();k++){
                    string p = s.substr(0,k+1)+"()"+s.substr(k+1);
                    // cout << p << endl;
                    if(isValid(p) && find(ans.begin(),ans.end(),p)==ans.end()){
                        ans.push_back(p);
                    }
                }
            }
        }
        vector <string> A;
        for(auto i:ans){
            if(i.size()==2*n)
                A.push_back(i);
        }
        return A;
    }
};
