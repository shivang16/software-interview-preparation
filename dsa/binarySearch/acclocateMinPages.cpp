#include<algorithm>
int countStudents(vector <int>& A,int mid){
    int students = 1;
    int pages = 0;
    for(auto i:A){
        if(pages+i<=mid){
            pages+=i;
        }else{
            students++;
            pages = i;
        }
    }
    return students;
}
int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if(B>n) return -1;
    sort(A.begin(),A.end());
    int l = A[n-1];
    
    int h = 0;
    for(auto i:A) h+=i;
    int mid = -1;
    while(h>=l){
        mid = (l+h)/2;
        int students = countStudents(A,mid);
        // cout << l << " " << mid << " " << h << " " << students << endl;
        if(students>B){
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    return l;
}
