class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int mn = prices[0];
        for(int i=1;i<n;i++){
            int profit = prices[i]-mn;
            ans = max(profit,ans);
            mn = min(mn,prices[i]);
        }
        return ans;
    }
};