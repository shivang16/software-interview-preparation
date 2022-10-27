int Solution::search(const vector<int> &A, int B) {\
    int l = 0,r=A.size()-1;
    while(r>=l){
        int mid = l+(r-l)/2;
        // cout << l << " " << r << " " << mid << endl;
        if(A[mid]==B)
            return mid;
        if(A[mid]>=A[l]){
            // Left sorted
            if(A[mid]>=B && A[l]<=B)
                r = mid-1;
            else
                l = mid+1;
        }else{
            // Right sorted
            if(A[mid]<=B && A[r]>=B)
                l = mid+1;
            else
                r = mid-1;
        }
    }
    return -1;
}
