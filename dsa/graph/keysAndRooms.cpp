// https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    int n;
    vector <bool> vis;
    void dfs(vector<vector<int>>& rooms,int x){
        vis[x] = true;
        for(int i=0;i<rooms[x].size();i++)
            if(!vis[rooms[x][i]])
                dfs(rooms,rooms[x][i]);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vis = vector <bool> (n,false);
        dfs(rooms,0);
        for(auto i:vis)
            if(!i)
                return false;
        return true;
    }
};