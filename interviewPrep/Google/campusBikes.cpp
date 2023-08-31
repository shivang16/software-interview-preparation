class Solution {
public:
    /**
     * @param workers: workers' location
     * @param bikes: bikes' location
     * @return: assign bikes
     */
    typedef pair <int,pair <int,int>> pr;
int getDistance(vector <int> &p1,vector <int>& p2){
    return abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
}
vector<int> assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
    priority_queue <pr,vector <pr>,greater <pr>> pq;
    vector <bool> visWorker(workers.size(),false), visBikes(bikes.size(),false);
    vector <int> ans(workers.size(),0);

    for(int i=0;i<workers.size();i++){
        for(int j=0;j<bikes.size();j++){
            // Distance, worker, bike
            pq.push({getDistance(workers[i],bikes[j]),{i,j}});
        }
    }
    int added = 0;
    while(!pq.empty() && added < workers.size()){
        int worker = pq.top().second.first;
        int bike = pq.top().second.second;
        // cout << pq.top().first <<" "<< worker << " " << bike << endl;
        while(!pq.empty() && !(visWorker[worker]==false and visBikes[bike]==false)){
            // cout << worker << " " << bike << " already added" << endl;
            pq.pop();
            worker = pq.top().second.first;
            bike = pq.top().second.second;
        }
        
        visWorker[worker] = true;
        visBikes[bike] = true;
        ans[worker] = bike;
        added++;
        // cout << worker << " " << bike << " added" << endl;
        pq.pop();
    }
    return ans;
    // write your code here

}
};