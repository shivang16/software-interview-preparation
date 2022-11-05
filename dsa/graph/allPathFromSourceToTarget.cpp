//https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    int n;
    vector <vector <int>> ans;
    vector <bool> vis;
    void dfs(vector<vector<int>>& graph, int x,vector <int> &temp){
        if(x==n-1){
            temp.push_back(n-1);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        // cout << x << endl;
        if(vis[x])
            return;
        vis[x] = true;
        temp.push_back(x);
        for(int i=0;i<graph[x].size();i++){
            // cout << i << "  " << graph[x][i] << endl;
            dfs(graph,graph[x][i],temp);
        }
        vis[x] = false;
        temp.pop_back();      
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vis = vector <bool> (n,false);
        // vis[0] = true;
        vector <int> temp;
        dfs(graph,0,temp);
        return ans;
    }
};