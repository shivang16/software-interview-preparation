// https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int mini(int a,int b,int c){
        return min(a,min(b,c));
    }
    int ans(string s1,int n1,string s2,int n2,vector <vector <int>> &dp){
        if(n1==0)
            return n2;
        if(n2==0)
            return n1;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        if(s1[n1-1]==s2[n2-1])
            dp[n1][n2] = ans(s1,n1-1,s2,n2-1,dp);
        else
            dp[n1][n2] = 1+mini(ans(s1,n1-1,s2,n2-1,dp),ans(s1,n1,s2,n2-1,dp),ans(s1,n1-1,s2,n2,dp));
        return dp[n1][n2];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(),n=word2.size();
        vector <vector <int>> dp(m+1,vector <int>(n+1,-1));
        return ans(word1,m,word2,n,dp);
    }
};