class Solution {
public:
    typedef pair <int,pair <int,int>> pr;
    void merge(int l,int r,int mid,vector <pr>& vec){
        int i = l,j = mid+1;
        int count = 0;
        vector <pr> temp;
        while(i<=mid && j<=r){
            if(vec[i].second.first > vec[j].second.first){
                count++;
                temp.push_back(vec[j]);
                j++;
            }else{
                vec[i].first+=count;
                temp.push_back(vec[i]);
                i++;
            }
        }
        while(i<=mid){
            vec[i].first+=count;
            temp.push_back(vec[i++]);
        }
        while(j<=r){
            temp.push_back(vec[j++]);
        }
        j=l;
        for(int i=0;i<temp.size();i++){
            vec[j++] = temp[i];
        }
    }
    void mergeSort(int l,int r,vector<pr> &vec){
        if(r>l){
            int mid = (r+l)/2;
            mergeSort(l,mid,vec);
            mergeSort(mid+1,r,vec);
            merge(l,r,mid,vec);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n,0);
        vector <pr> sortVec;
        for(int i=0;i<n;i++){
            sortVec.push_back({0,{nums[i],i}});
        }
        mergeSort(0,n-1,sortVec);
        for(auto i:sortVec){
            ans[i.second.second] = i.first;
        }
        return ans;
    }
};