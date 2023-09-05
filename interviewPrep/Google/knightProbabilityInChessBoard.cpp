// https://leetcode.com/problems/knight-probability-in-chessboard/submissions/
class Solution {
public:
    int X[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
    int Y[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };
    double fn(int n,int k,int row,int col,map<vector<int>,double> &mp){
        if(k==0) return 1.0;
        if(mp.count({row,col,k})) return mp[{row,col,k}];
        double ans=0.0;
        for(int i=0;i<8;i++){
            int x=X[i]+row;
            int y=Y[i]+col;
            if((x>=0 and x<n) and (y>=0 and y<n)){
                ans+=(fn(n,k-1,x,y,mp))/8.0;
            }
        }
        return mp[{row,col,k}]=ans;
    }
    double knightProbability(int n, int k, int row, int col) {
        map<vector<int>,double> mp;
        return fn(n,k,row,col,mp);
    }
};