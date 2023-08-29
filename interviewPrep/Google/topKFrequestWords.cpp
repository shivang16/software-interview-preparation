typedef pair <int,string> pp;
class Compare{
    public: 
        bool operator()(pp &p1,pp &p2){
            if(p1.first==p2.first){
                return p1.second > p2.second;
            }
            return p1.first < p2.first;
    }
};
if(p1.first < p2.first) return true;
        else if(p2.first > p1.first) return true;
        return p1.second < p2.second;
class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string,int> Mp;
        priority_queue <pp, vector <pp>, Compare> pq;
        for(auto i:words)
            Mp[i]++;
        vector <string> ans;
        for(auto i:Mp)
            pq.push({i.second,i.first});
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};