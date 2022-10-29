int Solution::candy(vector<int> &A) {
    int n = A.size();
    vector <int> dp(n,1);
    for(int i=1;i<A.size();i++)
    {
        if(A[i]>A[i-1])
            dp[i] = dp[i-1]+1;
    }
    for(int i=n-2;i>=0;i--){
        if(A[i]>A[i+1] && dp[i]<=dp[i+1]+1)
            dp[i] = dp[i+1]+1;
    }
    int ans = 0;
    for(int i=0;i<n;i++)
        ans+=dp[i];
    return ans;
    
}
