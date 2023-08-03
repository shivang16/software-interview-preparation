class Solution {
    
public:

    int findAns(string t1,string t2,int n1,int n2){
        if(n1<0 || n2<0) return 0;
        if(t1[n1]==t2[n2])
            return 1+findAns(t1,t2,n1-1,n2-1);
        return max(findAns(t1,t2,n1,n2-1),findAns(t1,t2,n1-1,n2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return findAns(text1,text2,text1.size()-1,text2.size()-1);
        int n1 = text1.size(), n2 = text2.size();
        vector <vector <int>> dp(n1+1,vector <int> (n2+1,0));
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1] = 1+dp[i][j];
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[n1][n2];
    }
};