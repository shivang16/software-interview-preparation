class Solution {
private:
    unordered_map <char,char> M;
public:
    /**
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    Solution(){
        
        M['0'] = '0';
        M['1'] = '1';
        M['6'] = '9';
        M['8'] = '8';
        M['9'] = '6';
    }
    bool isStrobogrammatic(string &num) {
        string num2 = num;
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num.size();i++){
            if(M.count(num[i])){
                if(num[i]!=M[num2[i]]) return false;
            }else{
                return false;
            }
        }
        return true;
        // write your code here
    }
};