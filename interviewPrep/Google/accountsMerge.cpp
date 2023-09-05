// https://leetcode.com/problems/accounts-merge/
class DisjointSet{
    private: 
        int N;
        vector <int> parent;
        vector <int> size;
    public: 
        DisjointSet(int n){
            N = n;
            for(int i=0;i<n;i++){
                parent.push_back(i);
                size.push_back(1);
            }
        }

        int getParent(int node){
            if(parent[node]==node) return node;
            return parent[node] = getParent(parent[node]);
        }

        bool findUnion(int u,int v){
            int pu = getParent(u);
            int pv = getParent(v);
            if(pu==pv) return false;
            int su = size[pu];
            int sv = size[pv];
            if(su>sv){
                parent[pv] = pu;
                size[pu]+=size[pv]; 
            }else{
                parent[pu] = pv;
                size[pv]+=size[pu];
            }
            return true;
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds(accounts.size());
        unordered_map <string,vector <int>> emailToId;
        for(int i=0;i<accounts.size();i++){
            int id = i;
            for(int j=1;j<accounts[i].size();j++){
                string email = accounts[i][j];
                if(emailToId.count(email)!=0){
                    for(auto crntId:emailToId[email]){
                        ds.findUnion(id,crntId);
                    }
                }
                emailToId[email].push_back(id);
            }
        }

        vector <vector <string>> ans;
        unordered_map <int,set <string>> idToEmail;

        for(int i=0;i<accounts.size();i++){
            int id = ds.getParent(i);
            for(int j=1;j<accounts[i].size();j++){
                idToEmail[id].insert(accounts[i][j]);
            }
        }
        for(auto acc: idToEmail){
            vector <string> temp;
            temp.push_back(accounts[acc.first][0]);
            for(auto name:acc.second)
                temp.push_back(name);
            ans.push_back(temp);
        }
        return ans;
    }
};