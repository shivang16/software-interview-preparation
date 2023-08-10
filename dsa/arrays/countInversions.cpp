#include <bits/stdc++.h> 

long long mergeArrays(long long *arr,int low,int mid,int high){
    vector <long long> vec;
    int i = low, j= mid+1;
    long long count = 0;
    while(i<=mid && j<=high){
        if(arr[i]>arr[j]){
            count+= (mid-i+1);
            vec.push_back(arr[j]);
            j++;
        }else{
            vec.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid){
        vec.push_back(arr[i++]);
    }
    while(j<=high){
        vec.push_back(arr[j++]);
    }
    i=low;
    for(auto el:vec){
        arr[i++] = el;
    }
    return count;
}

long long findInversions(long long *arr,int l,int h){
    if(l>=h) return 0;
    int mid = (l+h)/2;
    long long ans = 0;
    ans+=findInversions(arr,l,mid);
    ans+=findInversions(arr,mid+1,h);
    ans+=mergeArrays(arr,l,mid,h);
    return ans;
}
long long getInversions(long long *arr, int n){
    return findInversions(arr,0,n-1);
    // Write your code here.
}