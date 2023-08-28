class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector <int> adj[n];
        vector <int> indegree(n,0);
        for(auto i:relations){
            int u = i[0]-1, v = i[1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }

        // for(int i=0;i<n;i++){
        //     cout << i << ": " << indegree[i] << " -> ";
        //     for(auto j:adj[i])
        //         cout << j << " ";
        //     cout << endl;
        // }
        queue <int> Q;
        vector <int> dis(n,0);
        for(int i=0;i<n;i++){
            if(indegree[i]==0) {
                Q.push(i);
                dis[i] = time[i];
            }
            
        }
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            for(auto v:adj[u]){
                dis[v] = max(dis[v],dis[u]+time[v]);
                indegree[v]--;
                if(indegree[v]==0){
                    Q.push(v);
                }
            }
        }
        return *max_element(dis.begin(),dis.end());
    }
};