class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map <int,int> Mp;
        int n = tops.size();
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                Mp[tops[i]]++;
            }else{
                Mp[tops[i]]++;
                Mp[bottoms[i]]++;
            }
        }
        int val = -1;
        for(auto i:Mp){
            if(i.second>=n){
                val = i.first;
            }
        }
        if(val==-1) return -1;
        // cout << val << endl;
        int countU = 0, countD = 0;
        for(int i=0;i<n;i++){
            if(tops[i]==val){
                countU++;
            }
            if(bottoms[i]==val){
                countD++;
            }
        }
        // cout << count << endl;
        return min({countU,countD,n-countU,n-countD});
    }
};