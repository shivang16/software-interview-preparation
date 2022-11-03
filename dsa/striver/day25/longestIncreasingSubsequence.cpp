// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int n = A.size();
        if(n==0)
            return 0;
        int dp[n];
        dp[0] = 1;
        int mx = 1;
        for(int i=1;i<n;i++)
        {
            int m =1;
            for(int j=i-1;j>=0;j--)
            {
                if(A[i]>A[j])
                    m = max(m,1+dp[j]);
            }
            dp[i] = m;
            mx = max(m,mx);
        }
        return mx;
        
    }
};