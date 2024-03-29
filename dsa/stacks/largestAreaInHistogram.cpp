class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector <int> nextSmall(n,-1);
        vector <int> prevSmall(n,-1);
        stack <int> S;
        for(int i=0;i<n;i++){
            while(!S.empty() && heights[S.top()]>heights[i]){
                nextSmall[S.top()] = i;
                S.pop();
            }
            S.push(i);
        }
        while(!S.empty()) {
            S.pop();
        }
        // cout << S.top();
        for(int i=n-1;i>=0;i--){
            while(!S.empty() && heights[S.top()]>heights[i]){
                prevSmall[S.top()] = i;
                S.pop();
            }
            S.push(i);
        }
        for(int i=0;i<n;i++){
            if(nextSmall[i]==-1){
                nextSmall[i] = n;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int area;
            
                area = heights[i]*(nextSmall[i]-prevSmall[i]-1);
            // }
            ans = max(area,ans);
            // cout << heights[i] << ": " << nextSmall[i] << " " << prevSmall[i] << " "<<area << endl;
        }
        return ans;
    }
};