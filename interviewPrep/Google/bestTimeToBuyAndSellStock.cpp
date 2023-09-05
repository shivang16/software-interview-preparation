// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int ans = 0;
        for(auto i:prices){
            mini = min(mini,i);
            ans = max(ans,i-mini);
        }
        return ans;
    }
};