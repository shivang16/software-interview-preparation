//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
        int T[n],DP[n];
        memset(T,0,sizeof(T));
        memset(DP,0,sizeof(DP)); 
	    DP[0] = 1;
        T[0] = arr[0];
        int ans = arr[0];
        for(int i=1;i<n;i++){
            int temp = arr[i];
            int m = 1;
            for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                        m = max(m,DP[j]+1);
                        temp = max(temp,arr[i]+T[j]);
                }
            }
            DP[i] = m;
            T[i] = temp;
            ans = max(ans,T[i]);
        }
        return ans;

	    // Your code goes here
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends