// https://leetcode.com/problems/is-graph-bipartite/submissions/
class Solution {
public:
    bool applyCol(vector <vector <int>>& graph, vector <int> &col,int u,int crntCol){
        col[u] = crntCol;
        bool ans = true;
        for(auto v:graph[u]){
            if(col[v]==-1){
                ans &= applyCol(graph,col,v,!crntCol);
            }else if(col[v]==crntCol) return false;
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                bool ans = applyCol(graph,col,i,0);
                if(!ans) return false;
            }
        }        
        return true;
    }
};