// https://leetcode.com/problems/number-of-flowers-in-full-bloom/submissions/
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map <int,int> mp;
        for(auto i:flowers){
            mp[i[0]]++;
            mp[i[1]+1]--;
        }
        int sum = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto &i:mp){
            sum+=i.second;
            i.second=sum;
            mini = min(mini,i.first);
            maxi = max(maxi,i.first);
        }
        vector <int> ans;
        for(auto i:people){
            if(mp.count(i)){
                ans.push_back(mp[i]);
            }else{
                if(i<mini or i>maxi) ans.push_back(0);
                else{
                    auto itr = --mp.lower_bound(i);
                    ans.push_back(itr->second);
                }
            }
        }
        return ans;
    }
};