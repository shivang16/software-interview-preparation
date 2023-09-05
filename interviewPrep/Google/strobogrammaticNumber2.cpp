// https://www.lintcode.com/problem/776/
class Solution {
public:
    /**
     * @param n: the length of strobogrammatic number
     * @return: All strobogrammatic numbers
     *          we will sort your return value in output
     */
    void add(vector <string>& ans,string s,int n){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        if(s.size()!=n-2)
            add(ans,'0'+s+'0',n);
        add(ans,'1'+s+'1',n);
        add(ans,'6'+s+'9',n);
        add(ans,'8'+s+'8',n);
        add(ans,'9'+s+'6',n);
        
        
    }
    vector<string> findStrobogrammatic(int n) {
        vector <string> ans;
        if(n==0){
            ans.push_back("");
            return ans;
        }
        string s = "";
        if(n%2){
            s = "0";
            add(ans,s,n);
            s = "1";
            add(ans,s,n);
            s = "8";
            add(ans,s,n);
        }else{
            s = "";
            add(ans,s,n);
        }
        return ans;
    }
};