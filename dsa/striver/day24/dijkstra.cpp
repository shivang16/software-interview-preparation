//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector <int> ans(V,INT_MAX);
        vector <int> vis(V,0);
        priority_queue<pair<int,int>,vector <pair<int,int>>,greater<pair<int,int>>> Q;
        Q.push({0,S});
        ans[S] = 0;
        while(!Q.empty()){
            int u = Q.top().second;
            int dis = Q.top().first;
            Q.pop();
            for(auto i:adj[u]){
                if(ans[i[0]]>dis+i[1]){
                    ans[i[0]] = dis+i[1];
                    Q.push({ans[i[0]],i[0]});
                }
                
            }
        }
        // Code here
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends