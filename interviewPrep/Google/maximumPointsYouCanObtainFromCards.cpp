// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector <int> Ls,Rs;
        Ls.push_back(0);
        Rs.push_back(0);
        int sum = 0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
            Ls.push_back(sum);
        }
        if(k==n)
            return sum;
        sum=0;
        for(int i=n-1;i>=n-k;i--){
            sum+=cardPoints[i];
            Rs.push_back(sum);
        }

        int ans = 0;
        for(int i=0;i<=k;i++){
            // cout << Ls[i] << " " << Rs[i] << endl;
            int temp = Ls[i]+Rs[k-i];
            ans = max(ans,temp);
        }
        return ans;
    }
};