//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int sum[n];
	    for(int i=0;i<n;i++) sum[i] = arr[i];
	    int ans = arr[0];
	    for(int i=1;i<n;i++){
	        int j = i-1;
	        while(j>=0){
	            if(arr[j]<arr[i]){
	                sum[i] = max(sum[i],sum[j]+arr[i]);
	            }
	            j--;
	        }
	        ans = max(sum[i],ans);
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