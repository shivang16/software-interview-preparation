int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector <int> dp(n,1);
    int ans = 1;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(A[i]>A[j])
                dp[i] = max(dp[i],1+dp[j]);
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}
