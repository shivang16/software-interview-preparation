// https://leetcode.com/problems/keys-and-rooms/submissions/
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector <bool> &vis,int ind){
        if(vis[ind]) return;
        vis[ind] = true;
        for(auto i:rooms[ind]){
            dfs(rooms,vis,i);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector <bool> vis(n,false);
        dfs(rooms,vis,0);
        for(auto i:vis)
            if(!i)
                return false;
        return true;
    }
};