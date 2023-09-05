// https://leetcode.com/problems/number-of-provinces/submissions/
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j])
                    ds.findUnion(i,j);
            }
        }
        unordered_set <int> st;
        for(int i=0;i<n;i++)
            st.insert(ds.findParent(i));
        return st.size();
    }
};