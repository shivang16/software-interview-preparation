class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector <pair <int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector <double> disProb(n,INT_MIN);
        priority_queue <pair <double,int>> Q;
        Q.push({1.0,start_node});
        disProb[start_node] = 1;

        while(!Q.empty()){
            int crnt = Q.top().second;
            double prob = Q.top().first;
            Q.pop();
            for(auto i:adj[crnt]){
                int adjNode = i.first;
                double edW = i.second;
                if(disProb[adjNode]<prob*edW){
                    disProb[adjNode] = prob*edW;
                    Q.push({disProb[adjNode],adjNode});
                }
            }
        }
        if(disProb[end_node]==INT_MIN) return 0.0000;
        return disProb[end_node];
    }
};