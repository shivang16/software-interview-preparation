class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& a) {
        // a.push_back({target, 0});
        // priority_queue <int> q;
        // int ret = 0;
        // for (auto &x : a) {
        //     while (fuel < x[0] && !q.empty()) { // if we can't reach
        //         fuel += q.top(); q.pop(); // add fuel from previous stations
        //         ret++; // and update the answer as we are refueling.
        //     }
        //     if (fuel < x[0]) return -1; // there is no way to reach as we used all possible fuel.
        //     q.push(x[1]); // we have reached a new station, add it to the heap for later use.
        // }
        // return ret;
        int n = a.size();
        vector <int> dp(n + 1, fuel);
        for (int i = 0; i < n; i++) 
            for (int k = i; k >= 0; k--) 
				// if we can reach new station with k moves
                if (dp[k] >= a[i][0]) 
					// we will update the result for k + 1 moves as if we take this new station's fuel
                    dp[k + 1] = max(dp[k + 1], min(dp[k] + a[i][1], target));
        for (int k = 0; k <= n; k++)
            if (dp[k] >= target) return k;
        return -1;
    }
};