bool isPalindrom(string s,int st,int ed){
    while(ed>st){
        if(s[st++]!=s[ed--])
            return false;
    }
    return true;
}

int palindromePartitioning(string str)
{
    int n = str.size();
    vector <int> dp(n+1,0);
    dp[n] = 0;
    for(int i=n-1;i>=0;i--){
        int minCost = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrom(str,i,j)){
                int cost = 1+dp[j+1];
                minCost = min(minCost,cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0]-1;
        
    // Write your code here
}
