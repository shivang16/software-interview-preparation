class Solution {
public:
    bool canCol(vector<vector<int>>& graph, vector <int> &col,int ind,int crnt){
        col[ind] = crnt;
        for(auto i:graph[ind]){
            if(col[i]==-1){
                if(!canCol(graph,col,i,!crnt)) return false;
            }else{
                if(col[i]==col[ind]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!canCol(graph,col,i,0)) return false;
            }
        }
        return true;
    }
};