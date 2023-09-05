// https://leetcode.com/problems/interleaving-string/
class Solution {
public:
    int dp[101][101];
    bool solve(int x,int y,int z,string &s1,string &s2,string &s3)
    {   
        if(x==0 && y==0 && z==0)
            return true;
        if(dp[x][y]!=-1)
            return dp[x][y];
        bool a=false,b=false;
        if(x-1>=0 && z-1>=0 && s1[x-1]==s3[z-1])
            a=solve(x-1,y,z-1,s1,s2,s3);
        if(y-1>=0 && z-1>=0 && s2[y-1]==s3[z-1])
            b=solve(x,y-1,z-1,s1,s2,s3);
        return dp[x][y]=a||b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int x=s1.size();
        int y=s2.size();
        int z=s3.size();
        memset(dp,-1,sizeof(dp));
        bool ans=solve(x,y,z,s1,s2,s3);
        return ans;
    }
};