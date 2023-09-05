// https://www.lintcode.com/problem/817/
class SegmentTree{
    private: 
        int n;
        vector <int> arr;
        vector <int> seg;
        int query(int ind,int low,int high,int l, int r){
            if(low>=l && high<=r) return seg[ind];
            if(low>r || high<l) return 0;
            int mid = (low+high)/2;
            int left = query(2*ind+1,low,mid,l,r);
            int right = query(2*ind+2,mid+1,high,l,r);
            return left+right;
        }

        void build(int ind,int low,int high){
            if(low==high){
                seg[ind] = arr[low];
                return;
            }
            int mid = (low+high)/2;
            build(2*ind+1,low,mid);
            build(2*ind+2,mid+1,high);
            seg[ind] = seg[2*ind+1]+seg[2*ind+2];
        }
        
        void update(int ind,int low,int high,int target,int val){
            if(low==high){
                seg[ind] = val;
                return; 
            }
            int mid = (low+high)/2;
            if(target>=low && target<=mid)
                update(2*ind+1,low,mid,target,val);
            else
                update(2*ind+2,mid+1,high,target,val);
        }
    public:
        SegmentTree(vector <int> nums){
            arr = nums;
            n = arr.size();
            seg.resize(4*n);
            build(0,0,n-1);
        }

        int findBetweenRange(int low,int high){
            return query(0,low,high,0,n-1);
        }

        void updateValue(int target,int val){
            update(0,0,n-1,target,val);
        }
};


class NumMatrix {
    private: 
        vector <SegmentTree*> vec;
    public:
        NumMatrix(vector<vector<int>> matrix) {
            for(auto i:matrix){
                SegmentTree* temp = new SegmentTree(i);
                vec.push_back(temp);
            }
        }
        
        void update(int row, int col, int val) {
            vec[row]->updateValue(col,val);   
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            int sum = 0;
            for(int i=row1;i<=row2;i++){
                sum+= vec[i]->findBetweenRange(col1,col2);
            }
            return sum;
        }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */