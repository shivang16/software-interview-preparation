// https://leetcode.com/problems/ones-and-zeroes/solutions/3805157/c-memoization-tabulation/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<int>> curr(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> next(m + 1, vector<int>(n + 1, 0));


        for (int i = N-1; i >= 0; i--) {
            int ones = count(strs[i].begin(), strs[i].end(), '1');
            int zeros = strs[i].size() - ones;
            for (int j = zeros; j <= m; j++) {
                for (int k = ones; k <= n; k++) {
                    int take = 1 + next[j - zeros][k - ones];
                    int dontTake = next[j][k];
                    curr[j][k] = max(take, dontTake);
                }
            }
            next = curr;
        }

        return next[m][n];
    }
};