class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map <int,int> M;
        int low = 0, high = 0;
        int ans = INT_MAX;
        while(high<n){
            M[cards[high]]++;
            while(M[cards[high]]>1){
                ans = min(ans,high-low+1);
                M[cards[low]]--;
                low++;
            }
            high++;
        }
        return ans==INT_MAX?-1:ans;
    }
};