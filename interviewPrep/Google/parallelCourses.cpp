class Solution {
public:
    /**
     * @param n: the number of courses
     * @param relations: the relationship between all courses
     * @return: ehe minimum number of semesters required to complete all courses
     */
    int minimumSemesters(int n, vector<vector<int>> &relations) {
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
        for(int i=0;i<n;i++){
            if(indegree[i]==0) Q.push(i);
        }
        // cout << endl;
        int level = 0, seen = 0;
        while(!Q.empty()){
            int count = Q.size();
            seen+=count;
            level++;
            while(count--){
                int u = Q.front();
                Q.pop();
                for(auto v:adj[u]){
                    if(--indegree[v]==0){
                        Q.push(v);
                    }
                }
            }
        }

        return seen==n?level:-1;
    }
};