class DisjointSet{
    private:
        vector <int> parent,rank;
    public: 
        DisjointSet(int n){
            for(int i=0;i<n;i++){
                parent.push_back(i);
                rank.push_back(1);
            }
        }

        int findParent(int p){
            if(parent[p]==p) return p;
            return parent[p] = findParent(parent[p]);
        }

        bool findUnion(int u,int v){
            int parentU = findParent(u);
            int parentV = findParent(v);
            if(parentU==parentV) return false;
            int parentUSize = rank[parentU];
            int parentVSize = rank[parentV];
            
            if(parentUSize>parentVSize){
                parent[parentV] = parentU;
                rank[parentU]+=parentVSize;
            }else{
                parent[parentU] = parentV;
                rank[parentV]+=parentUSize;
            }
            return true;
        }

        int findNumberOfComponents(){
            int count = 0;
            for(int i=0;i<parent.size();i++){
                if(parent[i]==i)
                    count++;
            }
            return count;
        }
};


int m,n;
bool isValid(int x,int y){
    return x>=0 && x<m && y>=0 && y<n;
}
int X[4] = {1,-1,0,0};
int Y[4] = {0,0,-1,1};