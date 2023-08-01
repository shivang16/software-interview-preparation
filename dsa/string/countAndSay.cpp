class Solution {
public:
    string getCountAndSay(string s,int n){
        if(n==0) return s;
        int l = s.length();
        int i = 0;
        string s1 = "";
        while(i<l){
            int j = i+1;
            while(j<l && s[j]==s[i]) j++;
            int count = j-i;
            string say = to_string(count);
            string s2 = say+s[i];
            s1+=s2;
            i=j;
        }
        // cout << n << " " << s1 << endl;
        return getCountAndSay(s1,n-1);
    }
    string countAndSay(int n) {
        string s = "1";
        if(n==1) return s;
        return getCountAndSay(s,n-1);
    }
};