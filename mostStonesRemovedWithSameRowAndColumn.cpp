class disjointSet{
    public:
    vector<int>parent,size;
    disjointSet(int v){
        size.resize(v,1);
        parent.resize(v);
        for(int i=0;i<v;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return ;

        if(size[ulp_v]>size[ulp_u]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        disjointSet s(stones.size());
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if((stones[i][0]==stones[j][0]) || (stones[i][1]==stones[j][1])){
                        s.unionBySize(i,j);
                }
            }
        }

        int ans=0;
        set<int>st;
        for(int i=0;i<stones.size();i++){
            st.insert(s.findUPar(i));
        }
        return stones.size()-st.size();
        for(auto val:st){
            ans+=(s.size[val]-1);
        }

        return ans;
    }
};