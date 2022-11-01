// https://leetcode.com/problems/flood-fill/?envType=study-plan&id=graph-i
class Solution {
public:
    int X[4] = {0,0,1,-1};
    int Y[4] = {1,-1,0,0};
    int m,n;
    int val;
    void dfs(vector<vector<int>>& image,int x,int y,int color,vector <vector <bool>> &vis){
        if(x<0||x>=m||y<0||y>=n)
            return;
        if(vis[x][y])
            return;
        vis[x][y] = true;
        if(image[x][y]==val){
            image[x][y] = color;
        }else
            return;
        for(int i=0;i<4;i++){
            dfs(image,x+X[i],y+Y[i],color,vis);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size(),n=image[0].size();
        vector <vector <bool>> vis(m,vector <bool>(n,false));
        val = image[sr][sc];
        dfs(image,sr,sc,color,vis);
        return image;
    }
};