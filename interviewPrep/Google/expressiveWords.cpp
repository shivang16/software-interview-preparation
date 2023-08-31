class Solution {
public:
    vector <pair <char,int>> change(string s)
    {
        vector <pair <char,int>> v;
        for(int i=0;i<s.length();i)
        {
            int j = i;
            while(s[j]==s[i])
                j++;
            v.push_back({s[i],j-i});
            i = j;
        }
        return v;
    }
    bool comp(string s,string t)
    {
        if(s.length() < t.length())
            return false;
        if(s.length()==t.length())
            return s==t;
        vector <pair <char,int>> v1 = change(s);
        vector <pair <char,int>> v2 = change(t);
        
        if(v1.size()!=v2.size())
            return false;
        
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i].first!=v2[i].first)
                return false;
            else
            {
                // cout << v1[i].second << " " << v2[i].second << endl;
                int dif = v1[i].second -v2[i].second;
                if(dif==0)
                    continue;
                if(v1[i].second <v2[i].second)
                    return false;
                if(v1[i].second<3)
                    return false;
            }
        }
        
        return true;
    }
    int expressiveWords(string S, vector<string>& words) {
        int n = words.size();
        if(n==0)
            return 0;
        if(S==" ")
            return 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(comp(S,words[i]))
                ans++;
        }
        return ans;
            
        
    }
};