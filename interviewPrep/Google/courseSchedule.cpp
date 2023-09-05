// https://leetcode.com/problems/course-schedule
class Solution {
public:
    bool dfs(vector <int> Adj[],vector <int> &vis,int ind){
        if(vis[ind]==1) return true;
        if(vis[ind]==0) return false;
        vis[ind] = 0;
        for(auto i:Adj[ind]){
            if(!dfs(Adj,vis,i)) return false;
        }
        
        vis[ind] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector <int> Adj[numCourses];
       for(auto i:prerequisites){
           Adj[i[1]].push_back(i[0]);
       }
       vector <int> vis(numCourses,-1);
       for(int i=0;i<numCourses;i++){
           if(vis[i]==-1){
               if(!dfs(Adj,vis,i)) return false;
           }
       } 
       return true;
    }
};