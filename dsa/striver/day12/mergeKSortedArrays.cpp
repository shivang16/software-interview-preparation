#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector <int> ans;
//     priority_queue <pair <int,pair<int,int>>> Q;
//     for(int i=0;i<kArrays.size();i++){
//         Q.push({kArrays[i][0],{i,0}});
//     }
//     while(!Q.empty()){
//         int x = Q.top().second.second;
//         int y = Q.top().second.first;
//         int val = Q.top().first;
//         Q.pop();
//         ans.push_back(val);
//         if(x<kArrays[y].size()-1)
//             Q.push({kArrays[y][x+1],{y,x+1}});
//     }
    priority_queue <int> Q;
    for(int i=0;i<kArrays.size();i++){
        for(int j=0;j<kArrays[i].size();j++)
            Q.push(kArrays[i][j]);
    }
    while(!Q.empty()){
        ans.push_back(Q.top());
        Q.pop();
    }
    reverse(ans.begin(),ans.end());

    return ans;
    // Write your code here. 
}
