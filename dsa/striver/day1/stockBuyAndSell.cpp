class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = prices[0];
        int ans = 0;
        for(int i=1;i<n;i++){
            ans = max(prices[i]-mn,ans);
            mn = min(mn,prices[i]);
        }
        return ans;
        
    }
};