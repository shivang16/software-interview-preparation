// https://leetcode.com/problems/student-attendance-record-i/
class Solution {
public:
    bool checkRecord(string s) {
        int abTot = 0;
        int curLate = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                curLate++;
            }else{
                if(s[i]=='A')
                    abTot++;
                curLate = 0;
            }
            if(curLate>=3)
                return false;
            if(abTot>=2)
                return false;
            
        }
        return true;
    }
};