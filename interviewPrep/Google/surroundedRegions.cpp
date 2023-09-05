// https://leetcode.com/problems/surrounded-regions/description
class Solution {
public:
    int m,n;
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,-1,1};

    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }

    void dfs(vector<vector<char>>& board,vector <vector <bool>> &vis, int x,int y){
        if(!isValid(x,y)) return;
        if(vis[x][y]) return;
        if(board[x][y]=='X') return;
        // cout << x << " " << y << endl;
        vis[x][y] = true;
        for(int i=0;i<4;i++)
            dfs(board,vis,x+X[i],y+Y[i]);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        vector <vector <bool>> vis(m,vector <bool> (n,false));
        
        if(m==1||n==1) return;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(!vis[i][j] && board[i][j]=='O'){
                        dfs(board,vis,i,j);
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
    }
};