// https://leetcode.com/problems/network-delay-time/description/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <int> dis(n+1,1e9);
        vector <pair <int,int>> Adj[n+1];
        for(auto i:times){
            Adj[i[0]].push_back({i[1],i[2]});
        }
        
        priority_queue <pair <int,int>,vector <pair <int,int>>,greater<pair <int,int>>> Q;
        Q.push({0,k});
        dis[k] = 0;
        while(!Q.empty()){
            auto [time,ind] = Q.top();
            Q.pop();
            
            if(time > dis[ind]) continue;
            
            for(auto [adjNode, edjWt]:Adj[ind]){
                if(dis[adjNode] > time + edjWt){
                    dis[adjNode] = time+edjWt;
                    Q.push({dis[adjNode],adjNode});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            cout << i << " " << dis[i] << endl;
            ans = max(ans,dis[i]);
        }
        return ans==1e9?-1:ans;
    }
};