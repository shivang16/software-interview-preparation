
// https://leetcode.com/problems/swap-adjacent-in-lr-string/description/
class Solution {
public:
    bool canTransform(string start, string end) {
        int i=0,j=0;
        int n = start.size();
        while(i<n && j<n){
            while(start[i]=='X') i++;
            while(end[j]=='X') j++;
            if(start[i]!=end[j]) return false;
            if(start[i]=='R' && i>j) return false;
            if(start[i]=='L' && j>i) return false;
            i++;
            j++;
        }
        while(i<n && start[i]=='X') i++;
        while(j<n && end[j]=='X') j++;
        return i==j;
    }
};