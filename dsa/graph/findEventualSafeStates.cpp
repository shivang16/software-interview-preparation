class Solution {
    bool dfs(int node, vector<vector<int>>& g, vector<int> &vis, vector<int> &dfsvis) {
        vis[node] = 1;
        dfsvis[node] = 1;
        for(int ad : g[node]) {
            if(!vis[ad]) {
                if(dfs(ad, g, vis, dfsvis)) return true;
            }
            else if(dfsvis[ad]) return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n), dfsvis(n), ans;
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) dfs(i, graph, vis, dfsvis);
        }
        
        for(int i=0; i<n; i++) if(!dfsvis[i]) ans.push_back(i);
        return ans;
        
    }
};