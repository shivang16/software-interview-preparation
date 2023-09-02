class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set <int> availaible;
        for(int i=0;i<k;i++) availaible.insert(i);

        vector <int> usedCount(k,0);
        priority_queue <pair <int,int>,vector <pair <int,int>>, greater <pair <int,int>>> busy; // end time,server id -> min queue
        
        for(int i=0;i<arrival.size();i++){
            while(!busy.empty() && arrival[i]>=busy.top().first){
                availaible.insert(busy.top().second);
                busy.pop();
            }
            if(availaible.size()){
                // Finding first server with ind >= i%k 
                auto server = availaible.lower_bound(i%k);
                if(server==availaible.end()){
                    // If no such server is present then point to smalled indexed server
                    server = availaible.begin();
                }
                int serverId = *server;
                availaible.erase(server);
                int endTime = arrival[i]+load[i];
                usedCount[serverId]++;
                busy.push({endTime,serverId}); 
            }
        }
        int mx = *max_element(usedCount.begin(),usedCount.end());
        vector <int> ans;
        for(int i=0;i<usedCount.size();i++){
            if(usedCount[i]==mx){
                ans.push_back(i);
            }
        }
        return ans;
    }
};