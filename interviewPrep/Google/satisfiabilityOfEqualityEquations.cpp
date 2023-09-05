// https://leetcode.com/problems/satisfiability-of-equality-equations/
class Solution {
public:
    int parent[26];
    int size[26];
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
        cout << "union\n"<<endl;
        cout << u << " " << v << " " << findParent(u) << " " << findParent(v) << endl;
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++){
            parent[i] = i;
            size[i] = 1;
        }
        for(auto i:equations){
            if(i[1]=='='){  
                findUnionBySize(i[0]-'a',i[3]-'a');
            }
        }
        for(auto i:equations){
            if(i[1]!='='){  
                if(findParent(i[0]-'a')==findParent(i[3]-'a'))
                    return false;
            }
        }
        

        return true;
    }
};