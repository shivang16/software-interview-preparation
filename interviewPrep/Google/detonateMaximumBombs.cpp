class Solution {
    typedef long long ll;
private:
    void dfs(int node,vector<int>*adj,vector<bool>&vis,int &ANS){
        vis[node]=true;
        //Increasing the number of bombs detonated
        ANS+=1;
        //Going through all the adjacent/neighbours nodes
        for(auto &adjNode:adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode,adj,vis,ANS);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n=bombs.size();
        vector<int>adj[n];

        for(int i=0;i<n;i++){
            // this is the value of first point in graph and radius
            ll x1=(ll)bombs[i][0];
            ll y1=(ll)bombs[i][1];
            ll r1=(ll)bombs[i][2];
            for(int j=0;j<n;j++){
                // this is the value of second point in graph and radius
                ll x2=(ll)bombs[j][0];
                ll y2=(ll)bombs[j][1];
                ll r2=(ll)bombs[j][2];
                //Here we are finding the distance from point (x1,y1) to (x2,y2)
                ll DistanceBetweenx1ANDx2 = ( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
                //Checking whether the distance is less than or equal to r1 as up to r1 only our circle          
                //can stetch
                if(DistanceBetweenx1ANDx2 <= r1*r1){
                    // Here we can state that from index i to index j we can reach by using radius r1
                    adj[i].push_back(j);
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            if(!vis[i]){
                //Here initially we are keeping ANS=0 for every node to see that maximum number of bombs 
                //can be detonated  from node i
                int ANS=0;
                dfs(i,adj,vis,ANS);
                ans=max(ans,ANS);
            }
        }

        return ans;
    }
};