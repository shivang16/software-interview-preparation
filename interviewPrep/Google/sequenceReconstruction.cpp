// https://www.lintcode.com/problem/605/
class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        int count = 0;
        for(auto i:seqs)
            count+=i.size();
        if(org.size()==0){
            return count==0;
        }
        if(count<org.size()) return false;
        // if(seqs.size())
        int n = org.size();
        vector <int> inDeg(n,0);
        vector <int> Adj[n];
        for(auto i:seqs){
            for(int j=1;j<i.size();j++){
                int u = i[j-1]-1;
                int v = i[j]-1;
                if(u>=n or v>=n) return false;
                Adj[u].push_back(v);
                inDeg[v]++;
            }
            if(i.size() && i[0]-1 >=n) return false;
        }
        queue <int> Q;
        int ind = 0;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0) Q.push(i);
        }

        while(!Q.empty()){
            if(Q.size()>1) return false;
            int u = Q.front();
            // cout << u << endl;
            Q.pop();
            if(org[ind]-1!=u) return false;
            else ind++;
            for(auto v:Adj[u]){
                inDeg[v]--;
                if(inDeg[v]==0){
                    Q.push(v);
                }
            }
        }

        return ind==n;
        // write your code here
    }
};