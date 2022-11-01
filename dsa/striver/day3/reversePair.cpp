//https://leetcode.com/problems/reverse-pairs/
class Solution {
public:
    
    int merge(vector<int>& nums, int low,int mid, int high){
        int cnt=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high and nums[i] > 2LL *nums[j]){
                j++;
            }
            cnt += (j-(mid+1));
        }
        vector<int> temp;
        int left =low, right=mid+1;
        while(left <=mid and right <=high){
            if(nums[left] < nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left <=mid){
            temp.push_back(nums[left++]);
        }
        while(right<= high){
            temp.push_back(nums[right++]);
        }
        for(int i=low;i<=high;i++){
            nums[i] = temp[i-low];
        }
        return cnt;
    }
    
    int mergeSort(vector<int>& nums, int low, int high){
       if(low>=high){
           return 0;
       }
        int mid = (low+high)/2;
        int ans = mergeSort(nums,low,mid);
        ans += mergeSort(nums,mid+1,high);
        ans += merge(nums,low,mid,high);
        return ans;
    }
    
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};