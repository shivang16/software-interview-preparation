// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
class Solution {
public:
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector <pair <double,int>> ratioVec;
        for(int i=0;i<quality.size();i++){
            double ratio = wage[i]/(double)quality[i];
            ratioVec.push_back({ratio,quality[i]});
        }
        sort(ratioVec.begin(),ratioVec.end());
        priority_queue <int> pq;
        double ans = DBL_MAX;
        int qualSum = 0;
        for(auto i:ratioVec){
            qualSum+=i.second; // Getting sum of all the qualities;
            pq.push(i.second);
            if(pq.size() > k){
                qualSum-=pq.top(); // We have removed the person which was having more quality (as we had to pay him/her more)
                pq.pop();
            }
            if(pq.size()==k){
                ans = min(ans,i.first*qualSum);
            }
        }
        return ans;
    }
};