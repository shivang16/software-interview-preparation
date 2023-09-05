//  https://leetcode.chttps://leetcode.com/problems/maximum-number-of-accepted-invitations/a/all/1820.html
int maximumInvitation(vector <vector <int>> &grid){
    int m = grid.size(), n = grid[0].size();
    vector <bool> vis(n,false);
    unordered_map <int,vector <int>> B;
    vector <pair <int,int>> Ord;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j])
                B[i].push_back(j);
        }
        Ord.push_back({B[i].size(),i});
    }
    sort(Ord.begin(),Ord.end());
    int ans = 0;
    for(auto i:Ord){
        int boy = i.second;
        for(auto j:B[boy]){
            if(!vis[j]){
                ans++;
                vis[j] = true;
                break;
            }
        }
    }
    return ans;
}
int main() {
    vector <vector <int>> v1 = {{1,1,1},
                                {1,0,1},
                                {0,0,1}};
    cout << maximumInvitation(v1) << endl;
    
    vector <vector <int>> v2 = {{1,0,1,0},
                                {1,0,0,0},
                                {0,0,1,0},
                                {1,1,1,0}};
    cout << maximumInvitation(v2);
}