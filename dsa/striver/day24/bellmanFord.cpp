//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector <int> ans(V,1e8);
        ans[S] = 0;
        for(int i=1;i<V;i++){
            for(auto j:edges){
                int u = j[0],v=j[1],wt=j[2];
                ans[v] = min(ans[v],ans[u]+wt);
            }
        }
        bool flag = false;
        for(auto i:edges){
            int u = i[0],v=i[1],wt=i[2];
            if(ans[v]>ans[u]+wt){
                flag = true;
                break;
            }
        }
        if(flag){
            ans = vector <int> {-1};
        }
        return ans;
        // Code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends