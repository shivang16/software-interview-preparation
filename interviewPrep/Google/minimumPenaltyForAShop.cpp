// https://leetcode.com/problems/minimum-penalty-for-a-shop/
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector <int> pre(n+1,0), suf(n+1,0);
        pre[0] = 0;
        suf[n] = 0;
        for(int i=1;i<=n;i++){
            if(customers[i-1]=='N'){
                pre[i]++;
            }
            pre[i]+=pre[i-1];
        }

        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                suf[i]++;
            }
            suf[i]+=suf[i+1];
        }
        // for(int i=0;i<=n;i++){
        //     cout << i << " " << pre[i] << " " << suf[i] << endl;
        // }
        int mini = 0;
        for(int i=0;i<=n;i++){
            if(pre[i]+suf[i] < pre[mini]+suf[mini]){
                mini = i;
            }
        }
        return mini;
    }
};