class Solution {
public:
    int isMatching(string s,string p,int ind1,int ind2, vector <vector <int>> &dp){
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(ind1==s.size()){
            for(int i=ind2;i<p.size();i++){
                if(p[i]!='*') return dp[ind1][ind2] = 0;
            }
            return dp[ind1][ind2] = 1;
        }

        if(ind2==p.size()) return dp[ind1][ind2] = 0;

        if(p[ind2]<='z' && p[ind2]>='a'){
            if(s[ind1]!=p[ind2]) return dp[ind1][ind2] = 0;
            return dp[ind1][ind2] = isMatching(s,p,ind1+1,ind2+1,dp);
        }else if(p[ind2]=='?'){
            return dp[ind1][ind2] = isMatching(s,p,ind1+1,ind2+1,dp);
        }

        int ans = 0;
        for(int i=ind1;i<=s.size();i++){
            ans = ans+isMatching(s,p,i,ind2+1,dp);
        }
        return dp[ind1][ind2] = ans>=1;
    }
    bool isMatch(string s, string p) {
        if(s=="" && p=="") return true;
        if(p=="") return false;
        string newP = "";
        for(int i=0;i<p.size();){
            if(p[i]=='*'){
                int j = i+1;
                while(j<p.size() && p[j]=='*')
                    j++;
                newP+='*';
                i=j;
            }else{
                newP+=p[i];
                i++;
            }
                
        }
        vector <vector <int>> dp(s.size()+1,vector <int> (newP.size()+1,-1));
        return isMatching(s,newP,0,0,dp);
    }
};