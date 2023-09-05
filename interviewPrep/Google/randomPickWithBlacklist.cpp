// https://leetcode.com/problems/random-pick-with-blacklist/
class Solution {
private: 
    // {Wgt,{l,r}}
    vector <pair <int,pair <int,int>>> vec;
    vector <int> selectFirst;

    int getRandomInRange(int l,int r){
        int diff = (r-l+1);
        return l+rand()%diff;
    }

public:
    Solution(int n, vector<int>& blacklist) {
        sort(blacklist.begin(),blacklist.end());
        int l=0,r=0;
        
        for(int i=0;i<blacklist.size();i++){
            if(l==blacklist[i]){
                l++;
            }else
                r = blacklist[i]-1;
            if(r>=l){
                vec.push_back({r-l+1,{l,r}});
                l = blacklist[i]+1;
            }
        }
        if(n-1>=l){
            vec.push_back({n-l,{l,n-1}});
        }
        
        int sum = 0;
        for(auto i:vec){
            sum+=i.first;
            selectFirst.push_back(sum);
        }
    }
    
    int pick() {
        int val = rand()%(selectFirst.back());
        int ind = upper_bound(selectFirst.begin(),selectFirst.end(),val)-selectFirst.begin();
        // int ind = 0;
        return getRandomInRange(vec[ind].second.first,vec[ind].second.second);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */