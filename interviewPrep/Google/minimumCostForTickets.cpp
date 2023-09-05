// https://leetcode.com/problems/minimum-cost-for-tickets/submissions/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1);
        for (int i = 0; i < days.size(); i++) memo[i] = -1;
        return solve(days, costs, 0, memo); 
    }

private:
    int solve(vector<int>& days, vector<int>& costs, int idx, vector<int>& memo) {
        if (idx >= days.size()) return 0;
        if (memo[idx] != -1) return memo[idx];

        // Takes 1 day pass today
        int costDay = costs[0] + solve(days, costs, idx+1, memo);

        // Takes 7 day pass today
        int i = idx;
        while (i < days.size() && days[i] < days[idx] + 7) i++;
        int costWeek = costs[1] + solve(days, costs, i, memo);

        // Takes 30 day pass today
        i = idx;
        while (i < days.size() && days[i] < days[idx] + 30) i++;
        int costMonth = costs[2] + solve(days, costs, i, memo);

        return memo[idx] = min({costDay, costWeek, costMonth});
    }
};