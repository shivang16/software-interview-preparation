// https://leetcode.com/problems/majority-element-ii/submissions/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans;
        int ind1 = INT_MIN,count1=0;
        int ind2 = INT_MIN,count2=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==ind1){
                count1++;
            }else if(nums[i]==ind2){
                count2++;
            }else if(count1==0){
                ind1 = nums[i];
                count1 = 1;
            }else if(count2==0){
                ind2 = nums[i];
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
             
        }
        count1=count2=0;
        for(int i=0;i<n;i++)
            if(nums[i]==ind1)
                count1++;
        for(int i=0;i<n;i++)
            if(nums[i]==ind2)
                count2++;
        if(count1>n/3)
            ans.push_back(ind1);
        
        if(count2>n/3)
            ans.push_back(ind2);
        return ans;
    }
};