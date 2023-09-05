
void build(int ind,int low,int high,vector <int>& arr,vector <int>& seg){
    if(low==high){
        seg[ind] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid,arr,seg);
    build(2*ind+2,mid+1,high,arr,seg);
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
    return;
}

int query(int ind,int low,int high,int l,int r,vector <int>&seg){
    if(l<=low && r>=high) return seg[ind];
    if(l>high ||r<low ) return INT_MIN;
    
    int mid = (low+high)/2;
    int leftMin = query(2*ind+1,low,mid,l,r,seg);
    int rightMin = query(2*ind+2,mid+1,high,l,r,seg);
    return max(leftMin,rightMin);
}
int main(){
    vector <int> arr = {5,1,2,8,9,10,14,3,4};
    int n = arr.size();
    vector <int> seg(n*4+1,0);
    build(0,0,n-1,arr,seg);
    
    vector <vector <int>> q = {{1,4},{2,7},{0,4},{4,8},{0,8},{1,6},{5,7},{4,4}};
    
    for(auto i:q){
        cout << i[0] << " " << i[1] << " -> " << query(0,0,n-1,i[0],i[1],seg) << endl;
     }
}