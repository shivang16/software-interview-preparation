class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        map <int,int> Mp;
        for(int i=0;i<ranges.size();i++){
            Mp[i-ranges[i]]++;
            Mp[i+ranges[i]]--;
        }
        int count = 0;
        int ans = INT_MAX;
        for(auto i:Mp){
            count+=i.second;
            cout << i.first << " " << i.second << " " << count << endl;
            if(i.first >= 0 && i.first <=n){
                if(i.first==n && count<0)
                    return -1;
                else if(i.first!=n && count <=0)
                    return -1;    
                ans = min(ans,count);
            }
        }
        return ans==0?1:ans;
    }
};