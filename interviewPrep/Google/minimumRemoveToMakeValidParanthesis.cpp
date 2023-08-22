class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <pair <char,int>> St;
        unordered_set <int> Set;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){
                if(St.empty()){
                    St.push({s[i],i});
                }else if(St.top().first=='(' && s[i]==')'){
                    St.pop();
                }else{
                    St.push({s[i],i});
                }
            }
        }
        while(!St.empty()){
            Set.insert(St.top().second);
            St.pop();
        }
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(Set.find(i)==Set.end()) ans+=s[i];
        }
        return ans;

    }
};