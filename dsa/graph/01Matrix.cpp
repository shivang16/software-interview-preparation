// https://leetcode.com/problems/01-matrix/
class Solution {
public:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    int m,n;
    bool isValid(int x,int y){
        return x>=0&&x<m&&y>=0&&y<n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size(),n=mat[0].size();
        bool vis[m][n];
        memset(vis,false,sizeof(vis));
        vector <vector <int>> ans = mat;
        queue <pair <pair<int,int>,int>> Q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    Q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        while(!Q.empty()){
            auto frnt = Q.front();
            int x = frnt.first.first,y=frnt.first.second,dis=frnt.second;
            Q.pop();
            if(mat[x][y]==1){
                ans[x][y] = dis;
            }
            for(int i=0;i<4;i++){
                int nx = x+X[i],ny = y+Y[i];
                if(isValid(nx,ny) && !vis[nx][ny] && mat[nx][ny]==1){
                    vis[nx][ny] = true;
                    Q.push({{nx,ny},dis+1});
                }
            }
        }
        return ans;
    }
};