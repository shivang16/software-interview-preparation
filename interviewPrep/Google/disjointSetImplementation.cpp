
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    private: 
        int n;
        vector <int> parent,rank,size;
    public:
        DisjointSet(int n){
            n = n;
            for(int i=0;i<n;i++) parent.push_back(i);
            for(int i=0;i<n;i++) size.push_back(1);
            for(int i=0;i<n;i++) rank.push_back(0);
        }
    
        int findParent(int u){
            if(u==parent[u])
                return u;
            return parent[u] = findParent(parent[u]);
        }
        
        void findUnionByRank(int u,int v){
            int parentU = findParent(u);
            int parentV = findParent(v);
            if(parentU==parentV)
                return;
            int rankU = rank[parentU];
            int rankV = rank[parentV];
            if(rankU>rankV){
                parent[v] = parentU;
            }else if(rankU<rankV){
                parent[u] = parentV;
            }else{
                parent[u] = parentV;
                rank[parentV]++;
            }
        }
    
        void findUnionBySize(int u,int v){
            int parentU = findParent(u);
            int parentV = findParent(v);
            if(parentU==parentV)
                return;
            int sizeU = size[parentU];
            int sizeV = size[parentV];
            if(sizeU>sizeV){
                parent[v] = parentU;
                size[parentU]+=sizeV;
            }else{
                parent[u] = parentV;
                size[parentV]+=sizeU;
            }
        }
        
};

int main() {
    
    DisjointSet ds(8);
    ds.findUnionByRank(1,2);
    ds.findUnionByRank(4,5);
    ds.findUnionByRank(3,1);
    ds.findUnionByRank(1,4);
    ds.findUnionByRank(0,6);
    cout << ds.findParent(0) << " " << 0 << endl;
    cout << ds.findParent(1) << " " << 1 << endl;
    cout << ds.findParent(2) << " " << 2 << endl;
    cout << ds.findParent(3) << " " << 3 << endl;
    cout << ds.findParent(4) << " " << 4 << endl;
    cout << ds.findParent(5) << " " << 5 << endl;
    cout << ds.findParent(6) << " " << 6 << endl;
    cout << ds.findParent(7) << " " << 7 << endl;
    
}