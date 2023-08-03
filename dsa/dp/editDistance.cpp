class Solution {
public:
    
    int minDistance(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector <vector <int>> dp(n1+1,vector <int> (n2+1,0));
        for(int i=0;i<=n1;i++)
            dp[i][0] = i;
        for(int j=0;j<=n2;j++)
            dp[0][j] = j;
        
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1] = dp[i][j];
                }else{
                    dp[i+1][j+1] = 1+min({dp[i][j+1],dp[i+1][j],dp[i][j]});
                }
            }
        }
        return dp[n1][n2];
    }
};