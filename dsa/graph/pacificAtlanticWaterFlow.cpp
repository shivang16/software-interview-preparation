class Solution {
public:
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> atlantic, pacific;
    vector<vector<int>> ans;
    bool isValid(int x, int y, int m, int n){
        return x>=0 && x<m && y>=0 && y<n;
    }
    void dfs2(vector<vector<int>> heights, vector<vector<int>> &vis, int x, int y){
        if(vis[x][y]) return;
        int m=heights.size(), n=heights[0].size();
        vis[x][y]=1;
        if(atlantic[x][y] && pacific[x][y]) ans.push_back({x, y});
        for(auto d: dir)
            if(isValid(x+d.first, y+d.second, m, n) && 
                heights[x+d.first][y+d.second] >= heights[x][y] && vis[x+d.first][y+d.second]==0)
            dfs2(heights, vis, x+d.first, y+d.second);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        atlantic = vector<vector<int>>(m, vector<int>(n, 0));
        pacific = vector<vector<int>>(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++) dfs2(heights, pacific, i, 0), dfs2(heights, atlantic, i, n-1);
        for(int i=0; i<n; i++) dfs2(heights, pacific, 0, i), dfs2(heights, atlantic, m-1, i);
        return ans;
    }
};