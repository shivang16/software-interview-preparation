string longestCommonPrefix(vector<string>& strs) {

    string s=strs[0];
    int min=strs[0].size();
    for(int i=1;i<strs.size();i++)
    {
        if(strs[i].size()<min)
        {
            min=strs[i].size();
            s=strs[i];
        }
    }
    
    for(int i=0;i<strs.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            if(s[j]==strs[i][j])
                continue;
            else
                s.erase(s.begin()+j,s.end());
        }
    }
    return s;
    
}