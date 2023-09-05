// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/
class Solution {
public:
    int getAns(vector<int>& prices,vector <vector <int>> &dp,int ind,int k){
        if(ind>=prices.size() || k<=0) return 0;
        if(dp[ind][k]!=-1) return dp[ind][k];
        int notIncluded = getAns(prices,dp,ind+1,k); // not considering this element 
        int included = 0;
        if(k%2!=0){
            included = prices[ind]+getAns(prices,dp,ind+1,k-1);
        }else{
            included = -prices[ind]+getAns(prices,dp,ind+1,k-1);
        }
        return dp[ind][k] = max(notIncluded,included);
    }
    int maxProfit(vector<int>& prices) {
        int k = 2*2; // for buying and selling
        int n = prices.size();
        vector <vector <int>> dp(n,vector <int> (k+1,-1));
        return getAns(prices,dp,0,k);
    }
};