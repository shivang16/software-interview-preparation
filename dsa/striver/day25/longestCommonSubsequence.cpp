class Solution {
public:
    int ans(string s,string t,int n1,int n2){
        if(n1<0||n2<0) return 0;
        if(s[n1]==t[n2])
                return 1+ans(s,t,n1-1,n2-1);
        return max(ans(s,t,n1-1,n2),ans(s,t,n1,n2-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(),n2=text2.length();
        int DP[n1+1][n2+1];
        memset(DP,0,sizeof(DP));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1])
                    DP[i][j] = 1+DP[i-1][j-1];
                else
                    DP[i][j] = max(DP[i-1][j],DP[i][j-1]);

            }
        }
        return DP[n1][n2];
        // return ans(text1,text2,text1.length()-1,text2.length()-1);
    }
};