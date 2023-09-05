// https://leetcode.com/problems/number-of-operations-to-make-network-connected/submissions/
class DisjointSet{
private:
    vector <int> parent;
    vector <int> size;
    int N;
public:
    DisjointSet(int n){
        N = n;
        for(int i=0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }

    bool findUnion(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return false;
        int su = size[pu];
        int sv = size[pv];
        if(su>sv){
            parent[pv] = pu;
            size[su]+=sv;
        }else{
            parent[pu] = pv;
            size[sv]+=su;
        }
        return true;
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        if(connections.size()<n-1) return -1;

        for(auto i:connections){
            ds.findUnion(i[0],i[1]);
        }        auto i:n
        unordered_set <int> st;
        for(int i=0;i<n;i++)
            st.insert(ds.findParent(i));
        return st.size()-1;
    }
};