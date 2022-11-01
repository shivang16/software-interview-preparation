#define ll long long int
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
   
    ll x = 0;
    ll y = 0;
   
    for(int i=0;i<n;i++){
        ll e = (i+1);

// x contains difference of Sums
// x = actualSum - expectedSum
// x = repeated - missing; after for loop completed
        x += (A[i] - e);

//y : a2-b2 represented as (a+b)*(a-b)
// y contains difference of sum of squares
// y = actualSquareSum - expectedSquareSum;
// y = repeated^2 - missing^2; after for loop completed
        y += ((A[i] - e)*(A[i]+e));
    }
   
    ll z = y/x;
// z = repeated + missing
// since y = (repeated-missing)*(repeated+missing)
// x = repeated - missing
   
    ll r = (x+z)/2; // r represents repeated
    ll m = abs(z-r); // m represents missing
   
    vector<int> v;
    v.push_back((int)r);
    v.push_back((int)m);
   
    return v;
}
/*
    n*(n-1)/2 -x+y=t2;
    n*(n+1)*(2*n+1)/6 -x^2+y^2=t2
*/
