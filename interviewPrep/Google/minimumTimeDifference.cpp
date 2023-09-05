// https://leetcode.com/problems/minimum-time-difference/description
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector <int> temp;
        for(auto i:timePoints){
            int hh = stoi(i.substr(0,2));
            int mm = stoi(i.substr(3,2));
            temp.push_back(hh*60+mm);
            if(hh<12)
                temp.push_back((hh+24)*60+mm);
        }
        // for(auto i:temp) cout << i << endl;
        sort(temp.begin(),temp.end());
        
        int ans = INT_MAX;
        for(int i=1;i<temp.size();i++){
            int diff = abs(temp[i]-temp[i-1]);
            ans = min(ans,diff);
        }
        return ans;
    }
};