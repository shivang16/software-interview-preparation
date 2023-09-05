// https://www.lintcode.com/problem/787/
class Solution {
private:
    int hash(vector<int> &p) { return p[0] * 1000 + p[1]; }
    vector<int> go(vector<vector<int>>& maze, int x, int y, int d[2]) {
        int M = maze.size(), N = maze[0].size();
        do {
            x += d[0];
            y += d[1];
        } while (x >= 0 && x < M && y >= 0 && y < N && !maze[x][y]);
        return { x - d[0], y - d[1] };
    }
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<int> q;
        unordered_set<int> seen;
        int s = hash(start), dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        q.push(s);
        seen.insert(s);
        while (q.size()) {
            int val = q.front(), x = val / 1000, y = val % 1000;
            q.pop();
            if (x == destination[0] && y == destination[1]) return true;
            for (auto &dir : dirs) {
                auto to = go(maze, x, y, dir);
                int h = hash(to);
                if (seen.count(h)) continue;
                seen.insert(h);
                q.push(h);
            }
        }
        return false;
    }
};