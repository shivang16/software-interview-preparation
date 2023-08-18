class Solution {
public:
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
    int m,n;
    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue <pair <pair <int,int>, int>> Q;
        m = mat.size(), n = mat[0].size();

        vector <vector <int>> ans(m,vector <int> (n,0));
        
        vector <vector <bool>> vis(m,vector <bool> (n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    Q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }

        while(!Q.empty()){
            int x = Q.front().first.first;
            int y = Q.front().first.second;
            int dis = Q.front().second;
            Q.pop();
            ans[x][y] = dis;
            for(int i=0;i<4;i++){
                int nx = x+X[i];
                int ny = y+Y[i];
                if(isValid(nx,ny) && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    Q.push({{nx,ny},dis+1});
                }
            }
        }
        return ans;
    }
};