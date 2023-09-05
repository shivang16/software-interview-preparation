// https://leetcode.com/problems/course-schedule-ii/description
class Solution {
public:
    bool dfs(vector <int> Adj[],vector <int> &vis,stack <int> &S,int ind){
        if(vis[ind]==1) return true;
        if(vis[ind]==0) return false;
        vis[ind] = 0;
        for(auto i:Adj[ind]){
            if(!dfs(Adj,vis,S,i)) return false;
        }
        S.push(ind);
        vis[ind] = 1;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector <int> Adj[numCourses];
       for(auto i:prerequisites){
           Adj[i[1]].push_back(i[0]);
       }
       vector <int> vis(numCourses,-1);
       stack <int> S;
       vector <int> ans;
       for(int i=0;i<numCourses;i++){
           if(vis[i]==-1){
               if(!dfs(Adj,vis,S,i)) return ans;
           }
       } 
       while(!S.empty()){
           ans.push_back(S.top());
           S.pop();
       }
       return ans;
    }
};