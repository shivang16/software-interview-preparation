class Solution {
public:
    string reverseWords(string s) {
        if(s.length()==0)
            return s;
        bool flag = true;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                flag = false;
                break;
            }
        }
        if(flag)
            return "";
        string s1 =  "";
        for(int i=0;i<s.length();i++)
        {
            while(i<s.length() && s[i] ==' ')
                i++;
            //cout << i << endl;
            string temp = "";
            while(i<s.length() && s[i]!=' ')
               temp = temp+s[i++]; 
            s1 = temp+" "+s1;
        }
        if(s1[0]==' ')
            s1 = s1.substr(1,s1.length()-1);
        if(s1[s1.length()-1]==' ')
            s1 = s1.substr(0,s1.length()-1);
        return s1;
        
    }
};