// https://leetcode.com/problems/sort-integers-by-the-power-value/submissions/
class Solution {
public:
    int findPower(int n,unordered_map <int,int> &M){
        if(M.find(n)!=M.end()) return M[n];
        if(n%2)
            return M[n] = 1+findPower(3*n+1,M);
        else
            return M[n] = 1+findPower(n/2,M);
    }
    int getKth(int lo, int hi, int k) {
        priority_queue <pair <int,int>, vector <pair <int,int>>, greater<pair <int,int>>> Q;
        unordered_map <int,int> M;
        M[1] = 0;
        for(int i=lo;i<=hi;i++){
            int power = findPower(i,M);
            cout << i << " " << power << endl;
            Q.push({power,i});
        }
        while(--k)
            Q.pop();
        return Q.top().second;
        
    }
};