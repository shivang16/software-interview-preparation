class Solution {
public:
    bool dfs(vector <int> A[],vector <int>& col,int ind,int crnt){
        col[ind] = crnt;
        for(auto i:A[ind]){
            if(col[i] == -1){
                if(!dfs(A,col,i,!crnt)) return false;
            }else{
                if(col[i]==col[ind]) return false; 
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector <int> A[n];
        for(auto i:dislikes){
            A[i[0]-1].push_back(i[1]-1);
            A[i[1]-1].push_back(i[0]-1);
        }
        vector <int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!dfs(A,col,i,0))
                    return false;
            }
        }
        return true;
    }
};