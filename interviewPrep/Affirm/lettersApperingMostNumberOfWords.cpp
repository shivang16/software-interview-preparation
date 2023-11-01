#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<iterator>
using namespace std;

unordered_map <char,vector <char>> getAns(vector <string> str){
    int n = str.size();
    unordered_map <char,vector <char>> ans;
    unordered_map <char,unordered_map <char,int>> tempMp;
    for(auto s:str){
        unordered_map <char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        for(auto c:s){
            for(auto i:mp){
                if(i.first!=c)
                    tempMp[c][i.first]+=i.second;
            }
        }
    }

    for(auto i:tempMp){
        vector <char> counter;
        int mx = 0;
        for(auto j:i.second){
            if(j.second > mx){
                mx = j.second;
                counter.clear();
                counter.push_back(j.first);
            }else if(j.second==mx){
                counter.push_back(j.first);
            }
        }
        ans[i.first] = counter;
    }
    return ans;
}

void print(unordered_map <char,vector <char>> ans){
    for(auto i:ans){
        cout << i.first << "\n";
        for(auto j:i.second){
            cout << j << " ";
        }
        cout << "\n---\n";
    }
    cout << "========\n";
}
void solve()
{
    vector <string> str1 = {"abc","bdc","cde"};
    unordered_map <char,vector <char>> ans1 = getAns(str1); 
    print(ans1);
    vector <string> str2 = {"pqert","acbaper","pqirrtr","pqcmtm"};
    unordered_map <char,vector <char>> ans2 = getAns(str2); 
    print(ans2);
    vector <string> str3 = {"abc","abbes"};
    unordered_map <char,vector <char>> ans3 = getAns(str3); 
    print(ans3);
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    // cin >> t;
    t=1;
    while(t--)
    {
        solve();
    }
}