// https://leetcode.com/problems/rank-transform-of-a-matrix/description/
class Dsu {
private:
    vector<int>parent;
public:
    Dsu(int n){
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    
    int find(int x){
        if(parent[x] != x)parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)return;
        parent[y]=x;
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>ans(n, vector<int>(m));
        
        // want to process cell values from smallest to biggest
        // map cell values with cell coordinates
		 // c++ map maintains sorted order
        // repeated cell values => use vector<pair<int,int>>
        map<int, vector<pair<int,int>>> cellPos;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = matrix[i][j];
                cellPos[val].push_back({i,j});
            }
        }
        
        // track rowMaxRank, colMaxRank
        vector<int>rowMaxRank(n), colMaxRank(m);
        
        for(auto p:cellPos){
            Dsu dsu = Dsu(n+m);
            
            // unite nums on same row/col
            for(auto [row, col] : p.second){
                dsu.unite(row, col+n);
            }
            
            // calculate root ranks
            unordered_map<int,int>rootRank;
            for(auto [row, col] : p.second){
                int root = dsu.find(row);
                rootRank[root] = max(rootRank[root], max(rowMaxRank[row], colMaxRank[col])+1);
            }
            
            // calculate cell ranks and update rowMaxRank, colMaxRank
            for(auto [row, col] : p.second){
                int root = dsu.find(row);
                int rank = rootRank[root];
                ans[row][col] = rowMaxRank[row] = colMaxRank[col] = rank;
            }
        }
        
        return ans;
    }
};