// https://leetcode.com/problems/word-search/
class Solution {
public:
    int m,n;
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
    bool isValid(int x,int y){
        return x>=0 && x<m && y>=0 && y<n;
    }

    bool dfs(vector<vector<char>>& board, string &word, int x,int y,int ind,vector <vector <bool>> &vis){
        if(ind==word.size()) return true;
        if(!isValid(x,y)) return false;
        if(vis[x][y]) return false;
        if(word[ind]!=board[x][y]) return false;
        vis[x][y] = true;
        bool ans = false;
        for(int i=0;i<4;i++){
            int nx = x+X[i];
            int ny = y+Y[i];
            ans = ans||dfs(board,word,nx,ny,ind+1,vis);
        }
        vis[x][y] = false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        vector <vector <bool>> vis(m,vector <bool> (n,false));    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,i,j,0,vis))
                    return true;
            }
        }
        return false;
    }
};