// https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_975379?leftPanelTab=1
#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector <int> ans;
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
