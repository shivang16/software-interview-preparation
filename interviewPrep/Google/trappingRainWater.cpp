class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0, rightMax=0;
        int l = 0,h = height.size()-1;
        int ans = 0;
        while(h>=l){
            if(height[l] < height[h]){
                if(height[l]>leftMax){
                    leftMax = height[l];
                }else{
                    ans+= (leftMax-height[l]);
                }
                l++;
            }else{
                if(height[h]>rightMax)
                    rightMax = height[h];
                else
                    ans+=(rightMax-height[h]);
                h--;
            }
        }
        return ans;
    }
};