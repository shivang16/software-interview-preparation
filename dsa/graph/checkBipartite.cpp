class Solution {
public:
    int n;
    vector <int> color;
    bool dfs(vector<vector<int>>& graph,int v,int c){
        if(c==-1)
            color[v] = 0;
        else
            color[v] = c==0?1:0;
        // cout << v << " " << color[v] << " " << c << endl;
        bool x = true;
        for(auto i:graph[v]){
            if(color[i]==-1){
                x=x&&dfs(graph,i,color[v]);
            }else if(color[i]==color[v])
                return false;
        }
        return x;
    }
    bool bfs(vector<vector<int>>& graph,int p){
        queue <pair<int,int>> Q;
        Q.push({p,-1});
        while(!Q.empty()){
            int s = Q.size();
            while(s--){
                int v = Q.front().first,c = Q.front().second;
                Q.pop();
                if(c==-1)
                    color[v] = 0;
                else
                    color[v] = c==0?1:0;
                
                for(auto i:graph[v]){
                    if(color[i]==-1){
                        Q.push({i,color[v]});
                    }else if(color[i]==color[v])
                        return false;
                }
                

            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        color = vector <int>(n,-1);
        for(int i=0;i<n;i++)
            if(color[i]==-1){
                if(!bfs(graph,i))
                    return false;
            }
                
        return true;
    }
};