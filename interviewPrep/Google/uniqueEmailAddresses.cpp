class Solution {
public:
    string processEmail(string email){
        string ans = "";
        int ind = email.find('@');
        for(int i=0;i<ind;i++){
            if(email[i]=='.'){
                continue;
            }else if(email[i]=='+')
                break;
            else{
                ans+=email[i];
            }
        }
        return ans+email.substr(ind);
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set <string> address;
        for(auto i:emails){
            address.insert(processEmail(i));
        }
        return address.size();
    }
};