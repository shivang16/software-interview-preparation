class Solution {
public:
    typedef pair <long long,int> pr;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector <int> roomsUsed(n);
        
        sort(meetings.begin(),meetings.end());

        priority_queue <int, vector <int>, greater<int>> free;
        priority_queue <pr, vector <pr>, greater<pr>> busy;
        for(int i=0;i<n;i++) free.push(i);
        
        for(auto crntMeeting:meetings){
            while(!busy.empty() && busy.top().first <= crntMeeting[0]){
                free.push(busy.top().second);
                busy.pop();
            }    
            int room = -1;
            long long duration = crntMeeting[1]-crntMeeting[0];
            long long endTime = -1;
            if(!free.empty()){
                endTime = crntMeeting[1];
                room = free.top();
                free.pop();
                busy.push({endTime,room});
            }else{
                room = busy.top().second;
                endTime = busy.top().first+duration;
                busy.pop();
                busy.push({endTime,room});
            }
            roomsUsed[room]++;
        }

        int roomInd = 0, maxUsed = 0;
        for(int i=0;i<n;i++){
            if(roomsUsed[i]>maxUsed){
                maxUsed = roomsUsed[i];
                roomInd = i;
            }
        }
        return roomInd;
    }
};