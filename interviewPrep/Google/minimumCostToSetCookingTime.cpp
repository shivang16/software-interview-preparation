// https://leetcode.com/problems/minimum-cost-to-set-cooking-time/submissions/1034112312/
class Solution {
public:
    int findCost(int &startAt,int moveCost,int pushCost,int val){
        int ans = 0;
        if(startAt!=val){
            ans+=moveCost;
        }
        ans+=pushCost;
        startAt = val;
        // cout << ans << endl;
        return ans;
    }
    int findMinCost(int startAt,int moveCost,int pushCost,int min,int sec){
        // cout << min << " " << sec << endl;
        if(min==0 && sec==0) return 0;
        int ans = 0;
        int m0 = min%10, m1 = min/10, s0 = sec%10, s1 = sec/10;
        vector <int> time = {m1,m0,s1,s0};
        // cout << m1 << " " << m0 << " " << s1 << " " << s0 << endl;
        
        int ind = 0;
        while(ind<4 && time[ind]==0) ind++;
        // cout << ind << endl;
        for(int i=ind;i<4;i++){
            // cout << i <<" " << time[i] <<" " << startAt << " " << moveCost << " " << pushCost << " " << ans << endl;
            ans+=findCost(startAt,moveCost,pushCost,time[i]);
            // cout << ans << endl;
        }
        // cout << "ans: " << ans << endl;
        return ans;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int min1 = targetSeconds/60;
        int sec1 = targetSeconds%60;
        
        int min2 = -1, sec2=-1;
        if(min1 >=1 && sec1+60 <=99){
            min2 = min1-1;
            sec2 = sec1+60;
        }

        int ans = INT_MAX;
        if(min1<100)
            ans = findMinCost(startAt,moveCost,pushCost,min1,sec1);
        // cout << "ans: " << ans << endl;
        if(min2!=-1)
        ans = min(ans,findMinCost(startAt,moveCost,pushCost,min2,sec2));
        // cout << "ans: " << ans << endl;
        return ans;
    }
};