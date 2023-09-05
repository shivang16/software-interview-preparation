// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
class Solution {
private: 
    int dijkstra(vector <pair <int,int>> Adj[],int n,int start,int k){
    vector <int> dis(n,INT_MAX);
    priority_queue <pair <int,int>,vector <pair <int,int>>,greater <pair <int,int>>> pq;
    dis[start] = 0;
    pq.push({0,start});
    while(pq.size()){
        auto [w,u] = pq.top();
        pq.pop();
        for(auto [v,edg]: Adj[u]){
            if(dis[v]> w+edg){
                dis[v] = w+edg;
                pq.push({w+edg,v});
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(dis[i]<=k)
            ans++;
    }
    return ans;
}
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector <pair <int,int>> Adj[n];
        for(auto i:edges){
            Adj[i[0]].push_back({i[1],i[2]});
            Adj[i[1]].push_back({i[0],i[2]});
        }

        vector <int> dp(n,INT_MAX);
        int mn = INT_MAX;
        int ans = -1;
        for(int i=0;i<n;i++){
            dp[i] = dijkstra(Adj,n,i,distanceThreshold);
            if(dp[i]<=mn){
                ans = i;
                mn = dp[i];
            }
        }
        return ans;
    }
};