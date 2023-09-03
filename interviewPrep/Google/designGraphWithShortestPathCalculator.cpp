class Graph {
private:
    int N;
    vector <vector <pair <int,int>>> Adj;

    int dijkstra(int start,int end){
        vector <int> dis(N,INT_MAX);
        dis[start] = 0;
        priority_queue <pair <int,int>,vector <pair <int,int>>, greater <pair <int,int>>> pq;
        pq.push({0,start});
        while(!pq.empty()){
            int u = pq.top().second;
            int wgt = pq.top().first;
            pq.pop();
            for(auto [v,w]:Adj[u]){
                if(dis[v]> w+wgt){
                    dis[v] = w+wgt;
                    pq.push({w+wgt,v});
                }
            }
        }
        return dis[end];
    }
public:
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        Adj.resize(n);
        for(auto i:edges){
            Adj[i[0]].push_back({i[1],i[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        Adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int val = dijkstra(node1,node2);
        return val==INT_MAX?-1:val;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */