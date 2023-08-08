class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> ans;
        int n = nums.size();
        int el1 = INT_MIN, el2=INT_MIN;
        int sz1 = 0,sz2= 0;
        for(auto i:nums){
            if(sz1==0 && el2!=i){
                sz1 = 1;
                el1 = i;
            }else if(sz2 ==0 && el1!=i){
                sz2 = 1;
                el2 = i;
            }else if(i==el1){
                sz1++;
            }else if(i==el2){
                sz2++;
            }else{
                sz1--;
                sz2--;
            }
        }
        
        int count1 = 0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1)
                count1++;
            if(nums[i]==el2)
                count2++;
        }
        if(count1 > n/3)
            ans.push_back(el1);
        if(count2 > n/3)
            ans.push_back(el2);
        return ans;

    }
};