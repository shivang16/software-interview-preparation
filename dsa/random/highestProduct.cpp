int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
    int min1=INT_MAX,min2=INT_MAX,min3=INT_MAX;
    for(int i=0;i<n;i++){
        if(A[i]>=max1){
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        }else if(A[i]<max1 && A[i]>=max2){
            max3 = max2;
            max2 = A[i];
        }else if(A[i]<max2 && A[i]>=max3){
            max3 = A[i];
        }
        
        if(A[i]<=min1){
            min3 = min2;
            min2 = min1;
            min1 = A[i];
        }else if(A[i]>min1 && A[i]<=min2){
            min3 = min2;
            min2 = A[i];
        }else if(A[i]>min2 && A[i]<=min3){
            min3 = A[i];
        }
    }
    return max(max1*min1*min2,max1*max2*max3);
}
