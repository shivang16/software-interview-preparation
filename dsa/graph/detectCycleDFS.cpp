class Solution {
public:
    bool hasCycle(unordered_map <int,vector <int>> &M,vector <int> &vis,int ind){
        if(vis[ind]==0)
            return false;
        if(vis[ind]==1)
            return true;
        vis[ind] = 0;
        bool ans = true;
        for(auto i:M[ind]){
            ans = ans&&hasCycle(M,vis,i);
        }
        vis[ind] = 1;
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> vis(numCourses,-1);
        unordered_map <int,vector <int>> M;
        for(auto i:prerequisites){
            if(M.find(i[1])==M.end()){
                vector <int> temp;
                M[i[1]] = temp;
            }
            M[i[1]].push_back(i[0]);
        }
        bool cycleNotPresent = true;
        for(int i=0;i<numCourses;i++){
            if(vis[i]==-1){
                cycleNotPresent = cycleNotPresent&&hasCycle(M,vis,i);
            }
        }
        return cycleNotPresent;
    }
};