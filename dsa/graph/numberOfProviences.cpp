// https://leetcode.com/problems/number-of-provinces/
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int v,vector <int> &vis){
        vis[v] = 1;
        for(int i=0;i<isConnected[v].size();i++){
            if(isConnected[v][i]==1&& vis[i]==0)
                dfs(isConnected,i,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector <int> vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(isConnected,i,vis);
                ans++;
            }
        }
        return ans;
            
    }
};