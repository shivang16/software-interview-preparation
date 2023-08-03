#include <bits/stdc++.h> 

void topo(unordered_map <int,vector <int>> &M, int ind,stack <int> &s,vector <bool> &vis){
    vis[ind] = true;
    for(auto i:M[ind]){
        if(!vis[i]){
            topo(M,i,s,vis);
        }
    }
    s.push(ind);
}

vector <int> findSort(unordered_map <int,vector <int>> &M,int v){
    vector <int> ans;
    stack <int> s;
    vector <bool> vis(v,false);
    for(int i=0;i<v;i++){
        if(!vis[i])
            topo(M,i,s,vis);
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
    
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map <int,vector <int>> M;
    vector <int> temp;
    for(int i=0;i<v;i++) M[i] = temp;
    for(auto i:edges){
        M[i[0]].push_back(i[1]);
    }
    vector <int> ans = findSort(M,v);
    return ans;
}