class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& pass, int cap) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &it : pass){
            pq.push(it);
        }
        unordered_set<int> st;
        int n = buses.size();
        int val = cap;
        sort(buses.begin(),buses.end());
        for(int i = 0;i<n;i++){
            val = cap;
            if(i == n-1){
                while(!pq.empty() && pq.top()<=buses[i] && val>1){
                        st.insert(pq.top());
                        pq.pop();
                        val--;
                }
                int vali = 0;
                if(pq.empty())
                vali = buses[i];
                else vali = min(buses[i],pq.top()-1);
                while(st.count(vali))
                    vali--;
                return vali;
            }
            while(!pq.empty() && pq.top()<=buses[i] && val){
                st.insert(pq.top());
                pq.pop();
                val--;
            } 
        }
        return 0;
    }
};