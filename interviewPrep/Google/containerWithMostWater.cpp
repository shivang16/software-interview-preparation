// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size()-1;
        int i=0, j=n;
        int ans=0;
        while(i <= j){
            int area=0;
            int ht = min(height[i], height[j]);
            area = (j-i)*ht;
            ans = max(ans, area);
            if(height[i] > height[j]) j--;
            else i++;
        }

        return ans;
    }
};