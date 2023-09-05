// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack <char> S;
        for(auto i:s){
            if(i=='(' || i=='{' || i=='[')
                S.push(i);
            else{
                if(S.empty()) return false;
                char c = S.top();
                if(i==')' && c!='(') return false;

                if(i=='}' && c!='{') return false;

                if(i==']' && c!='[') return false;
                S.pop();
            }
        }
        return S.empty();
    }
};