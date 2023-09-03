// OJ: https://leetcode.com/problems/the-maze-ii/
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int shortestDistance(vector<vector<int>>& A, vector<int>& S, vector<int>& E) {
        int M = A.size(), N = A[0].size(), step = 0, dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

        vector<vector<vector<bool>>> seen(M, vector<vector<bool>>(N, vector<bool>(4))); // (x, y, direction)
        
        queue<array<int, 3>> q;
        
        for (int i = 0; i < 4; ++i) {
            seen[S[0]][S[1]][i] = true;
            q.push({S[0], S[1], i});
        }
        
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto [x, y, dir] = q.front();
                q.pop();
                auto &[dx, dy] = dirs[dir];
                int nx = x + dx, ny = y + dy;
        
                if (nx < 0 || nx >= M || ny < 0 || ny >= N || A[nx][ny]) { // The ball hits a wall. We can probe 4 directions
                    if (x == E[0] && y == E[1]) return step; // we can only check (x, y) if we are by a wall
                    for (int d = 0; d < 4; ++d) {
                        if (d == dir) continue;
                        auto &[dx, dy] = dirs[d];
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N || A[nx][ny] || seen[nx][ny][d]) continue;
                        seen[nx][ny][d] = true;
                        q.push({nx, ny, d});
                    }
                } else if (!seen[nx][ny][dir]) { // The ball doesn't hit a wall. We can only move in the same direction.
                    seen[nx][ny][dir] = true;
                    q.push({nx, ny, dir});
                }
            }
            ++step;
        }
        return -1;
    }
};