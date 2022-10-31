class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.length()<k)
            return s;
        stack <pair<char,int>> S;
        
        for(int i=0;i<s.length();i++){
            if(S.empty() || S.top().first!=s[i])
                S.push({s[i],1});
            else if(S.top().first==s[i])S.top().second++; 
            // cout << S.top().first << " " << S.top().second<<endl;
            if(S.top().second==k)
                S.pop();   
        }
        string ans = "";
        while(!S.empty()){
            while(S.top().second--){
                ans +=S.top().first;
            }
            S.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};