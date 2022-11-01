//https://leetcode.com/problems/count-sub-islands/

class Solution {
public:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    int m,n;
    void dfsFill(vector<vector<int>>& grid2,int x,int y,vector <vector <bool>> &vis,vector <pair<int,int>> &temp){
        if(x<0||x>=m||y<0||y>=n)
            return;
        if(vis[x][y]||grid2[x][y]==0)
            return;
        vis[x][y] = 1;
        temp.push_back({x,y});
        for(int i=0;i<4;i++)
            dfsFill(grid2,x+X[i],y+Y[i],vis,temp);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m=grid1.size(),n=grid1[0].size();
        vector <vector <pair <int,int>>> island;
        vector <vector <bool>> vis1(m,vector <bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis1[i][j] && grid2[i][j]==1){
                    vector <pair<int,int>> temp;
                    dfsFill(grid2,i,j,vis1,temp);
                    island.push_back(temp);
                }            
            }
        }
        // for(auto i:island){
        //     for(auto j:i){
        //         cout << j.first << " " << j.second << endl;
        //     }
        //     cout << "\n----------\n";
        // }
        vector <vector <bool>> vis2(m,vector <bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis2[i][j] && grid1[i][j]==1){
                    vector <pair<int,int>> temp;
                    dfsFill(grid1,i,j,vis2,temp);
                }
            }
        }
        int ans = 0;
        for(auto i:island){
            bool flag = true;
            for(auto j:i){
                if(!vis2[j.first][j.second])
                    flag = false;
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};