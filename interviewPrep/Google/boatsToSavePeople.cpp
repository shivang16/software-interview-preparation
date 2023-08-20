class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans = 0;
        int l = 0,r = people.size()-1;
        while(r>=l){
            if(r==l){
                ans++;
                break;
            }
            if(people[r]+people[l]<=limit){
                ans++;
                r--;
                l++;
            }else{
                r--;
                ans++;
            }
        }
        return ans;
    }
};