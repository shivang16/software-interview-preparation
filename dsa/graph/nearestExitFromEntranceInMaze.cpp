// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
class Solution {
public:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    int ans = INT_MAX;
    int m,n;
    int ex,ey;
    bool isEntrance(int x,int y){
        return x==ex&&y==ey;
    }
    bool isValid(int x,int y){
        return x>=0&&x<m&&y>=0&&y<n;
    }
    bool isBoundary(int x,int y){
        return x==0||x==m-1||y==0||y==n-1;
    }
//     void dfs(vector<vector<char>>& maze,int x,int y,vector <vector <bool>> &vis,int temp){
//         if(!isValid(x,y)||vis[x][y]||isEntrance(x,y)||maze[x][y]=='+')
//             return;
//         if(isBoundary(x,y)){
//             ans = min(ans,temp);
//             return;
//         }
//         vis[x][y] = true;
//         for(int i=0;i<4;i++)
//             dfs(maze,x+X[i],y+Y[i],vis,temp+1);
//         vis[x][y] = false;
        
//     }
//     int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
//         m = maze.size(),n=maze[0].size();
//         ex = entrance[0],ey=entrance[1];
//         int temp = 1;
//         vector <vector <bool>> vis(m,vector <bool> (n,false));
//         vis[ex][ey] = true;
//         for(int i=0;i<4;i++)
//         {
//             dfs(maze,ex+X[i],ey+Y[i],vis,temp);
//         }
//         return ans==INT_MAX?-1:ans;
//     }
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            m = maze.size(),n=maze[0].size();
            ex = entrance[0],ey=entrance[1];
            vector <vector <bool>> vis(m,vector <bool> (n,false));
            queue <pair <int,pair<int,int>>> Q;
            Q.push({0,{ex,ey}});
            vis[ex][ey] = true;
            while(!Q.empty()){
                pair <int,pair<int,int>> fr = Q.front();
                Q.pop();
                int x = fr.second.first,y=fr.second.second,dis=fr.first;
                if(isBoundary(x,y) && !isEntrance(x,y))
                    return dis;
                for(int i=0;i<4;i++){
                    int nx = X[i]+x,ny=Y[i]+y;
                    if(isValid(nx,ny)&&!vis[nx][ny]&&maze[nx][ny]=='.')
                        Q.push({dis+1,{nx,ny}}),vis[nx][ny]=true;
                }
            }
            return -1;
    }
    
};