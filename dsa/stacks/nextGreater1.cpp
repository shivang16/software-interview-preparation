class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector <int> ng(n2,-1);
        stack <int> S;
        unordered_map <int,int> M;
        for(int i=0;i<n2;i++){
            M[nums2[i]] = i;
            while(!S.empty() && nums2[S.top()]<nums2[i]){
                ng[S.top()] = nums2[i];
                S.pop();
            }
            S.push(i);
        }
        vector <int> ans;
        for(auto i:nums1){
            ans.push_back(ng[M[i]]);
        }
        return ans;
        
    }
};