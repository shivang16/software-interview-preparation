class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: the minimize travel distance
     */
    int calDistance(pair <int,int> p1,pair <int,int> p2){
        return abs(p1.first-p2.first)+abs(p1.second-p2.second);
    }

    int minTotalDistance(vector<vector<int>> &grid) {
        // Write your code here
        int m = grid.size(), n = grid[0].size();
        vector <pair <int,int>> friends;
        int xTot = 0,yTot = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    xTot+=i;
                    yTot+=j;
                    friends.push_back({i,j});
                }
            }
        }
        int fSz = friends.size();
        vector <pair <int,int>> dis;
        int xAvg = xTot/fSz, yAvg = yTot/fSz;
        dis.push_back({xAvg,yAvg});
        dis.push_back({xAvg+1,yAvg});
        dis.push_back({xAvg,yAvg+1});
        dis.push_back({xAvg+1,yAvg+1});
        int ans = INT_MAX;
        for(auto i:dis){
            if(i.first >=0 && i.first <m && i.second>=0 && i.second<n){
                int dis = 0;
                for(auto j:friends){
                    dis+=calDistance(i,j);
                }
                ans = min(dis,ans);
            }
        }
        
        return ans;
    }
};