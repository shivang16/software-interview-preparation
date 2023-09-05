// https://leetcode.com/problems/basic-calculator/
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack <int> st;

        int num = 0;
        int ans = 0;
        int sign = 1;

        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num = num*10+(s[i]-'0');
            }else if(s[i]=='+' || s[i]=='-'){
                ans+=(num*sign);
                num = 0;
                sign = s[i]=='+'?1:-1;
            }else if(s[i]=='('){
                st.push(ans);
                st.push(sign);
                ans = 0;
                num = 0;
                sign = 1;
            }else if(s[i]==')'){
                ans += (num*sign);
                num = 0;

                int stack_sign = st.top();
                st.pop();
                int stack_val = st.top();
                st.pop();

                ans *= stack_sign;
                ans += stack_val;
            }
        }
        ans += (num*sign);
        return ans;
    }
};