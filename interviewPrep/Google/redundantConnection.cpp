// https://leetcode.com/problems/redundant-connection
class Solution {
public:
    //Parent, size
    vector <pair <int,int>> node;
    int n;
    int findParent(int p){
        if(node[p].first==p)
            return p;
        return node[p].first = findParent(node[p].first);
    }

    bool findUnion(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return false;
        int su = node[pu].second;
        int sv = node[pu].second;
        if(su<sv){
            node[pv].second+=node[pu].second;
            node[pu].first = pv;
        }else{
            node[pu].second+=node[pv].second;
            node[pv].first = pu;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        for(int i=0;i<=n;i++){
            node.push_back({i,1});
        }
        vector <int> ans;
        for(auto i:edges){
            if(!findUnion(i[0],i[1])){
                ans = i;
                return ans;
            }
        }
        return ans;
    }
};