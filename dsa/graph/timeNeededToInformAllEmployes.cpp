class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //BFS
        vector <int> vis(n,false);
        queue <pair <int,int>> Q;
        Q.push({headID,informTime[headID]});
        vis[headID] = true;
        int ans = 0;
        vector <int> G[n];
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1){
                G[manager[i]].push_back(i);
            }
        }
        while(!Q.empty()){
            int id = Q.front().first,time=Q.front().second;
            ans = max(ans,time);
            Q.pop();
            for(auto i:G[id]){
                if(!vis[i]){
                    Q.push({i,informTime[i]+time});
                    vis[i] = true;
                }
            }
            
        }
        return ans;
    }
};