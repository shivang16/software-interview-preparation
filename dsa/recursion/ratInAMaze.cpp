int X[4] = {-1,1,0,0};
int Y[4] = {0,0,-1,1};
char D[4] = {'U','D','L','R'};
int n;
bool isValid(int x,int y){
    return x>=0 && x<n && y>=0 && y<n;
}

void dfs(vector<vector<int>> &mat, int r,int c,vector <string>& ans,string &temp,vector <vector <bool>> &vis){
    if(!isValid(r,c)) return;
    // cout << r << " " << c << " " << vis[r][c] << " " << mat[r][c] << " " << temp << endl;
    if(r==n-1 && c==n-1){
        ans.push_back(temp);
        return;
    }
    if(vis[r][c]) return;
    if(mat[r][c]==0) return;
    vis[r][c] = true;
    for(int i=0;i<4;i++){
        temp+=D[i];
        dfs(mat,r+X[i],c+Y[i],ans,temp,vis);
        temp.pop_back();
    }
    vis[r][c] = false;
}
vector<string> ratMaze(vector<vector<int>> &mat) {
    n = mat.size();
    // cout << n << endl;
    vector <vector <bool>> vis(n,vector <bool>(n,false));
    vector <string> ans;
    if(mat[n-1][n-1]==0)
        return ans;
    string temp = "";
    dfs(mat,0,0,ans,temp,vis);
    return ans;
    // Write your code here.
}