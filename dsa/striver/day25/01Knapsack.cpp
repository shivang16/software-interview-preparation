//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int getAns(int W, int wt[], int val[],int i,vector <vector <int>> &dp){
        if(i<0 || W<=0)
            return 0;
        if(dp[i][W]!=-1) return dp[i][W];
        if(wt[i]<=W)
            return dp[i][W] = max(val[i]+getAns(W-wt[i],wt,val,i-1,dp),getAns(W,wt,val,i-1,dp));
        else 
            return dp[i][W] = getAns(W,wt,val,i-1,dp);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector <vector <int>> dp(n,vector <int>(W+1,-1));
        return getAns(W,wt,val,n-1,dp);
       // Your code here
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends