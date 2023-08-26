class Solution {
public:
    int hIndex(vector<int>& citations) {
      sort(citations.begin() , citations.end());
			int l = 0 , h = citations.size()-1;
			int n = citations.size();
			int ans = 0; // to store ans 
			while(l <= h){
				int mid  = (h+l)/2;
			    int idx = n  - mid ; // index = total number of papers - mid(almost half)
				if(citations[mid] >= idx){ 
					ans = idx;
					h = mid-1; //we want to include more papers for citations(maximize ans )
				}
				else{
					l = mid +1;
				}
			}
			return ans;
    }
};