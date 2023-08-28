https://leetcode.com/playground/gugincJX
// OJ: https://leetcode.com/problems/path-with-maximum-minimum-value/
// Time: O(MNlog(MN))
// Space: O(MN)
class Solution {
    typedef array<int, 3> T;
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
        priority_queue<T> pq;
        pq.push({A[0][0],0,0});
        A[0][0] = -1;
        while (pq.size()) {
            auto [score, x, y] = pq.top();
            pq.pop();
            if (x == M - 1 && y == N - 1) return score;
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N || A[a][b] == -1) continue;
                pq.push({ min(score, A[a][b]), a, b });
                A[a][b] = -1;
            }
        }
        return -1;
    }
};