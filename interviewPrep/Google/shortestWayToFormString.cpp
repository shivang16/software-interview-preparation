// https://leetcode.ca/2018-10-20-1055-Shortest-Way-to-Form-String/
class Solution {
public:
    /**
     * @param s: Source string
     * @param target: Target string
     * @return: Number of subsequences that can be spliced into target
     */
    int getInd(string &s,char c,int ind){
        auto itr = find(s.begin()+ind,s.end(),c); 
        if(itr==s.end()) return -1;
        return itr-s.begin(); 
    }
    int shortestWay(string &s, string &target) {
        int count = 0,sz = s.size();
        int ind = 0;
        for(int i=0;i<target.size();i++){
            if(ind==sz){
                ind = 0;
                count++;
            }
            ind = getInd(s,target[i],ind);
            // cout << ind << " " << count << endl;
            if(ind==-1){
                ind = 0;
                ind = getInd(s,target[i],ind);
                if(ind==-1) return -1;
                count++;
            }else{}
            ind++;
        }
        return count+1;
        // write your code here
    }
};