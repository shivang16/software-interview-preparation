vector<int> Solution::maxone(vector<int> &a, int b) {
    int i,j,k,n,m,p,t ;
    n = a.size() ;
    m = 0 ;
    int start=0 ;
    t = 0 ;
    for(i=0;i<n;i++) {
        if(a[i] == 0) m++ ;
        if(m > b) {
            while(a[start] != 0) start++ ;
            start++ ;
            m-- ;
        }
        if(t < i-start+1) {
            t = i-start+1 ;
            j = start ;
        }
    }
    vector<int> v ;
    for(i=j;i<j+t;i++) v.push_back(i) ;
    return v ;
}
