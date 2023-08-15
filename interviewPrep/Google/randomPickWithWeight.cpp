// https://leetcode.com/problems/random-pick-with-weight/description/
class Solution {
public:
    vector <int> v;
    Solution(vector<int>& w) {
        int sum = 0;
        for(auto i:w){
            sum+=i;
            v.push_back(sum);
        }
    }   
    
    int pickIndex() {
        int num = rand()%v.back();
        return upper_bound(v.begin(),v.end(),num)-v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */