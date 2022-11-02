// https://leetcode.com/problems/as-far-from-land-as-possible/
class Solution {
public:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector <vector <bool>> vis(n,vector <bool> (n,false));
        queue <pair <int,pair <int,int>>> Q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(grid[i][j])
                    Q.push({0,{i,j}});
        }
        if(Q.size()==0||Q.size()==n*n)
            return -1;
        int ans = 0;
        while(!Q.empty()){
            int dis = Q.front().first,x=Q.front().second.first,y=Q.front().second.second;
            Q.pop();
            ans = max(ans,dis);         
            for(int i=0;i<4;i++){
                int nx = x+X[i],ny = y+Y[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0 && !vis[nx][ny]){
                    Q.push({dis+1,{nx,ny}});
                    vis[nx][ny] = true;
                }
            }
        }
        return ans;
    }
};