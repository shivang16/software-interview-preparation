class Solution {
public:
    
    int bfs(int start,vector <int> Adj[],int n){
        int ans = INT_MAX;
        vector <int> dis(n,INT_MAX);
        vector <int> par(n,-1);
        queue <int> Q;
        Q.push(start);
        dis[start] = 0;
        while(!Q.empty()){
            int crnt = Q.front();
            Q.pop();
            for(auto i:Adj[crnt]){
                if(par[i]==-1){
                    dis[i] = dis[crnt]+1;
                    Q.push(i);
                    par[i] = crnt;
                }else{
                    if(par[i]!=crnt && par[crnt]!=i){
                        ans = min(ans,dis[i]+dis[crnt]+1);
                    }
                }
            }
        }
        return ans;
    }
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector <int> Adj[n];
        for(auto i:edges){
            Adj[i[0]].push_back(i[1]);
            Adj[i[1]].push_back(i[0]);
        }
        
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,bfs(i,Adj,n));
        }
        return ans==INT_MAX?-1:ans;
    }
};