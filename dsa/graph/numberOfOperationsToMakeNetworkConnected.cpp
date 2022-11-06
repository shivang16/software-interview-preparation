// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    void dfs(vector <int> adj[],int v,vector <int> &vis){
        vis[v] = 1;
        for(auto i:adj[v]){
            if(!vis[i])
                dfs(adj,i,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ed = connections.size();
        if(ed<n-1)
            return -1;
        vector <int> adj[n];
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        // for(auto i:adj){
        //     for(auto j:i)
        //         cout << j << " ";
        //     cout << endl;
        // }
        vector <int> vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                ans++;
            }
        }
        return ans-1;
    }
};