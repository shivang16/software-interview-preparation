class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map <int,int> Mp;
        int l = 0,r = 0;
        int ans = 0;
        while(r<n){
            Mp[fruits[r]]++;
            while(l<=r && Mp.size()>2){
                Mp[fruits[l]]--;
                if(Mp[fruits[l]]==0){
                    Mp.erase(fruits[l]);
                }
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};