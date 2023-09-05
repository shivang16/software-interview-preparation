// https://leetcode.com/problems/count-positions-on-street-with-required-brightness/
#include<bits/stdc++.h>
using namespace std;

int getNumberOfPositions(int n,vector <vector <int>> &lights,vector <int> &requirement){
    int lz = lights.size();
    map <int,int> M;
    for(auto i:lights){
        int l = max(0,i[0]-i[1]);
        int r = max(n-1,i[0]+i[1]);
        M[l]++;
        M[r+1]--;
    }
    int ans = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        count+=M[i];
        if(count>=requirement[i])
            ans++;
    }
    return ans;
}

int main() {
    vector <vector <int>> lights = {{0,1},{2,1},{3,2}};
    vector <int> requirements = {0,2,1,4,1};
    cout << getNumberOfPositions(5,lights,requirements) << endl;
    lights = {{0,1}};
    requirements = {2};
    cout << getNumberOfPositions(1,lights,requirements) << endl;
    
}