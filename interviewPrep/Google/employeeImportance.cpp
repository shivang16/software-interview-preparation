// https://leetcode.com/problems/employee-importance/description/
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map <int,pair <int,vector <int>>> Adj;
        for(auto i:employees){
            Adj[i->id] = {i->importance,i->subordinates};
        }

        int ans = 0;
        queue <int> Q;
        Q.push(id);
        while(!Q.empty()){
            int tid = Q.front();

            ans+=Adj[tid].first;
            Q.pop();
            for(auto i:Adj[tid].second){
                Q.push(i);
            }
        }
        return ans;
    }
};