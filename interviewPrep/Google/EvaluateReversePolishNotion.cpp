// https://leetcode.com/problems/evaluate-reverse-polish-notation/description
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> S;
        for(auto i:tokens){
            if(i=="+"){
                int num1 = S.top();
                S.pop();
                int num2 = S.top();
                S.pop();
                S.push(num1+num2);
            }else if(i=="-"){
                int num1 = S.top();
                S.pop();
                int num2 = S.top();
                S.pop();
                S.push(num2-num1);
            }else if(i=="*"){
                int num1 = S.top();
                S.pop();
                int num2 = S.top();
                S.pop();
                S.push(num1*num2);
            }else if(i=="/"){
                int num1 = S.top();
                S.pop();
                int num2 = S.top();
                S.pop();
                S.push(num2/num1);

            }else{
                int num = stoi(i);
                S.push(num);
            }
        }
        return S.top();
    }
};