// https://leetcode.com/problems/number-of-provinces/description/


class Solution {
public:
    vector <int> parent;
    vector <int> size;
    int n;
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
            size[pv]+=size[u]; 
        }else{
            parent[pv] = pu;
            size[pu]+=size[v];
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        for(int i=0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j])
                    findUnionBySize(i,j);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(findParent(i)==i){
                ans++;
                cout << i << endl;
            }
                
        }
        return ans;
    }
};