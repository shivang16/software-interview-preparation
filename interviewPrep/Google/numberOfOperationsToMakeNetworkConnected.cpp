// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
class Solution {
public:
    vector <int> parent;
    vector <int> size;
    int findParent(int p){
        if(parent[p]==p)
            return p;
        return parent[p] = findParent(parent[p]);
    }

    void findUnionBySize(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        // cout << u << " " << v << " " << pu << " " << pv << endl;
        if(pu==pv) return;
        int su = size[pu];
        int sv = size[pv];
        // cout << su << " " << sv << endl;
        if(su<sv){
            parent[pu] = pv;
            size[pv]+=size[pu]; 
        }else{
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        for(int i=0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
        for(int i=0;i<connections.size();i++){
            findUnionBySize(connections[i][0],connections[i][1]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(findParent(i)==i)
                ans++;
        }
        return ans-1;
    }
};