class Solution {
public:
    bool isDigit(char c){
        return c>='0' && c<='9';
    }
    string decodeString(string s) {
        int n = s.size();
        stack <string> St;
        for(int i=0;i<n;i++){

            if(isDigit(s[i])){
                // cout << "isDigit: " << i << endl;
                int j = i;
                string num = "";
                while(j<n && isDigit(s[j])){
                    num+=s[j];
                    j++;
                }
                St.push(num);
                // cout << St.top() << endl;
                i = j;
            }else if(s[i]==']'){
                string str = "";
                while(St.size() && !isDigit(St.top()[0])){
                    str = St.top()+str;
                    St.pop();
                }

                // cout << St.top() << " " << str << endl;
                int count = stoi(St.top());
                St.pop();
                string temp = "";
                while(count--){
                    temp+=str;
                }
                St.push(temp);        
            }else{
                string temp = "";
                temp+=s[i];
                St.push(temp);
            }
        }

        string ans = "";
         
        while(St.size()){
            ans=St.top()+ans;
            St.pop();
        }
        return ans;
    }
    
};