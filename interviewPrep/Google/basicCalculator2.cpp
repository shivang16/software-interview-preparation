// https://leetcode.com/problems/basic-calculator-ii/
class Solution {
public:
    int giveResult(string num1,string num2,string op){
        int n1 = stoi(num1), n2 = stoi(num2);
        if(op=="+")
            return n1+n2;
        else if(op=="-")
            return n1-n2;
        else if(op=="*")
            return n1*n2;
        return n1/n2;
    }
    int calculate(string s) {
        int ans = 0;
        stack <string> st;
        int n = s.size();
        int number = 0;
        // cout << "safe zone" << endl;
        for(int i=0;i<n;i++){
            // cout << i << endl;
            if(isdigit(s[i])){
                string num = "";
                int j = i;
                while(j<n && isdigit(s[j]))
                    num+=s[j++];
                i = j-1;
                // cout << num << endl;
                if(st.empty()) 
                    st.push(num);
                else if(st.top()=="+")
                    st.push(num);
                else if(st.top()=="-"){
                    num = st.top()+num;
                    st.pop();
                    st.push("+");
                    st.push(num);
                }
                else{
                    string op = st.top(); st.pop();
                    string num2 = st.top(); st.pop();
                    st.push(to_string(giveResult(num2,num,op)));
                }
            }else if(s[i]==' '){
                continue;
            }
            else{
                string op = "";
                op+=s[i];
                st.push(op);
            }
            // cout << "I am here" << endl;
        }
        // cout << "reached here" << endl;"3+2*2"
        while(st.size()!=1){
            string num1 = st.top(); st.pop();
            string op = st.top(); st.pop();
            string num2 = st.top(); st.pop();
            st.push(to_string(giveResult(num2,num1,op)));
        }
        return stoi(st.top());
    }
};