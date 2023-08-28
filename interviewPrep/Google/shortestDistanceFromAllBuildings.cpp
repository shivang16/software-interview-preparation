class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return -1;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> buildingPositions;
        
        // Step 1: Find building positions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    buildingPositions.emplace_back(i, j);
                }
            }
        }
        
        // Initialize distance grid and reachable buildings count
        vector<vector<int>> distances(m, vector<int>(n, 0));
        vector<vector<int>> reachableBuildings(m, vector<int>(n, 0));
        
        // Step 2: Calculate distances from each empty land to all buildings
        for (const auto& building : buildingPositions) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({building.first, building.second});
            
            int dist = 0;
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; ++i) {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    
                    for (const auto& dir : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                        int newRow = row + dir.first;
                        int newCol = col + dir.second;
                        
                        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol] && grid[newRow][newCol] == 0) {
                            visited[newRow][newCol] = true;
                            distances[newRow][newCol] += dist + 1;
                            reachableBuildings[newRow][newCol]++;
                            q.push({newRow, newCol});
                        }
                    }
                }
                ++dist;
            }
        }
        
        // Step 3: Find the minimum sum of distances from empty lands
        int minDistance = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && reachableBuildings[i][j] == buildingPositions.size()) {
                    minDistance = min(minDistance, distances[i][j]);
                }
            }
        }
        
        return minDistance != INT_MAX ? minDistance : -1;
    }
};