// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>min){
                ans+= (prices[i]-min);
            }
            min = prices[i];
        }
        return ans;
    }
};