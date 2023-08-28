class Solution {
public:
    
    int minJumps(vector<int>& arr) {
        unordered_map <int,vector <int>> M;
        vector <int> vis(arr.size(),-1);
        
        for(int i=0;i<arr.size();i++)
            M[arr[i]].push_back(i);
        
        queue <pair <int,int>> Q;
        Q.push({0,0});
        while(!Q.empty()){
            auto [ind,dis] = Q.front();
            Q.pop();
            if(ind==arr.size()-1) return dis;
            vis[ind] = dis;
            if(ind>0 && vis[ind-1]==-1){
                Q.push({ind-1,dis+1});
            }
            if(ind<arr.size()-1 && vis[ind+1]==-1){
                Q.push({ind+1,dis+1});
            }
            for(auto i:M[arr[ind]]){
                if(vis[i]==-1){
                    Q.push({i,dis+1});
                }
            }
            M[arr[ind]].clear();
        }
        return INT_MAX;
    }
};