// https://leetcode.com/problems/student-attendance-record-ii
#define ll long long int
int mod=1e9+7;
class Solution {
public:

    int f(int lt,int ab,int sz,vector<vector<vector<int>>>&dp)
    {
        // lt number of consecutive late
        // ab number of absents
        // sz size of array or can be considerd as present

        if(sz==0)
        {
            return 1;
        }

        if(dp[sz][lt][ab]!=-1)
        {
            return dp[sz][lt][ab];
        }

        // Calling for student present on this day
        ll p1=f(0,ab,sz-1,dp);

        ll p2=0,p3=0; // Initializing possibility2 and possibility3

        if(lt<2)
        {
            // calling for student is late
            p2=f(lt+1,ab,sz-1,dp);
        }

        if(ab==0)
        {
            // calling for student is abscent
            p3=f(0,1,sz-1,dp);
        }

        // answer is total of all three conditions
        ll ans=(p1+p2+p3)%mod;

        return dp[sz][lt][ab]=ans;

        
    }

    int checkRecord(int n) {
        //vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));

        // memoization by suing f() function
        // return f(0,0,n,dp);

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2)));

        // Tabulation

        // initializing dp vector for sz=0 setting dp[0][lt][ab]=1

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                dp[0][i][j]=1;
            }
        }

        for(int sz=1;sz<=n;sz++)
        {
            for(int lt=0;lt<3;lt++)
            {
                for(int ab=0;ab<2;ab++)
                {
                    ll p1=dp[sz-1][0][ab];
                    ll p2=0,p3=0;

                    if(lt<2)
                    {
                        p2=dp[sz-1][lt+1][ab];
                    }

                    if(ab==0)
                    {
                        p3=dp[sz-1][0][1];
                    }

                    ll ans=(p1+p2+p3)%mod;
                    dp[sz][lt][ab]=ans;
                }
            }
        }
        return dp[n][0][0];

        
    }
};