class NumArray {
private:
    vector <int> arr;
    vector <int> seg;
    int n;
    void buildTree(int ind,int low,int high){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        buildTree(2*ind+1,low,mid);
        buildTree(2*ind+2,mid+1,high);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }

    int query(int ind,int low,int high,int l,int r){
        if(low>=l && high<=r) return seg[ind];
        if(high<l || low>r) return 0;
        int mid = (low+high)/2;
        int leftSum = query(2*ind+1,low,mid,l,r);
        int rightSum = query(2*ind+2,mid+1,high,l,r);
        return leftSum+rightSum;
    }

    void updateVal(int ind,int low,int high,int target,int val){
        if(low==high){
            seg[ind] = val;
            return;
        }
        int mid = (low+high)/2;
        if(target>=low && target<=mid){
            updateVal(2*ind+1,low,mid,target,val);
        }else{
            updateVal(2*ind+2,mid+1,high,target,val);
        }
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
public:
    
    NumArray(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        seg.resize(4*n,0);
        buildTree(0,0,n-1);
    }
    
    void update(int index, int val) {
        updateVal(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */