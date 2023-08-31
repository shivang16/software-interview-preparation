class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for(int i = 0; i < flowers.size(); i++){
            days[flowers[i] - 1] = i + 1;
        }
        int left = 0 , right = k + 1, ans = INT_MAX;
        for (int i = 0; right < days.size(); i++){
            if(days[i] < days[left] || days[i] < days[right] || i == right){
                if(i == right) ans = min(ans, max(days[right], days[left]));
                left = i;
                right = i + k + 1;
            }
        }

        return (ans == INT_MAX) ?-1: ans;
    }
};