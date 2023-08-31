class Solution {
public:
    /**
     * @param m: an integer
     * @param n: an integer
     * @return: the total number of unlock patterns of the Android lock screen
     */
    int dfs(vector <bool> &vis,vector <vector <int>>& skip,int crnt,int rem){
        if(rem<0) return 0;
        if(rem==0) return 1;
        vis[crnt] = true;
        int ans = 0;
        for(int i=1;i<=9;i++){
            if(!vis[i] && (skip[crnt][i]==0 || vis[skip[crnt][i]])){
                ans+=dfs(vis,skip,i,rem-1);
            }
        }
        vis[crnt] = false;
        return ans;

    }
    int numberOfPatterns(int m, int n) {
        // Write your code here
        vector <bool> vis(10,false);
        vector <vector <int>> skip(10,vector <int> (10,0));
        skip[1][3] = skip[3][1] = 2;
        skip[4][6] = skip[6][4] = 5;
        skip[7][9] = skip[9][7] = 8;
        skip[1][7] = skip[7][1] = 4;
        skip[2][8] = skip[8][2] = 5;
        skip[3][9] = skip[9][3] = 6;
        skip[1][9] = skip[9][1] = 5;
        skip[7][3] = skip[3][7] = 5;
        
        int ans = 0;
        for(int i=m;i<=n;i++){
            ans+=dfs(vis,skip,1,i-1)*4;
            ans+=dfs(vis,skip,2,i-1)*4;
            ans+=dfs(vis,skip,5,i-1);
        }
        return ans;

    }
};