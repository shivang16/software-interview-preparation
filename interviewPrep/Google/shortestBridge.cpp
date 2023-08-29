class Solution {
public:
    int n;
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,-1,1};
    bool isValid(int x,int y){
        return x>=0 && x<n && y>=0 && y<n;
    }

    void dfsChange(vector <vector <int>>& grid,int x,int y,vector <vector <bool>>& vis){
        if(!isValid(x,y)) return;
        if(vis[x][y] || grid[x][y]==0) return;
        vis[x][y] = true;
        grid[x][y] = 2;
        for(int i=0;i<4;i++){
            dfsChange(grid,x+X[i],y+Y[i],vis);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();

        vector <vector <bool>> vis(n,vector <bool> (n,false));
        bool oneFound = false;
        for(int i=0;i<n;i++){
            if(oneFound)
                break;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfsChange(grid,i,j,vis);
                    oneFound = true;
                    break;
                }
            }
        }    
        queue <pair <int,int>> Q;
        int lev = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) 
                    Q.push({i,j});
                // cout << grid[i][j] << " ";
            }
            // cout << endl;
        }
        // vis.resize(n,vector <bool> (n,false));
        while(!Q.empty()){
            int sz = Q.size();
            cout << lev << endl;
            while(sz--){
                int x = Q.front().first;
                int y = Q.front().second;
                // cout << x << " " << y << " " << grid[x][y] << endl;
                Q.pop();
                if(grid[x][y]==1) return lev-1;
                for(int i=0;i<4;i++){
                    int nx = x+X[i];
                    int ny = y+Y[i];
                    if(isValid(nx,ny) && !vis[nx][ny]){
                        // cout << "pushed" << endl;
                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
            }
            lev++;
        }
        return 0;
    }
};