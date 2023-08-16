class Solution {
public:
    char findTheDifference(string s, string t) {
        int m1[26],m2[26];
        memset(m1,0,sizeof(m1));
        memset(m2,0,sizeof(m2));
        for(auto i:s)
            m1[i-'a']++;
        for(auto i:t)
            m2[i-'a']++;
        for(int i=0;i<26;i++){
            if(m1[i]!=m2[i]){
                // cout << 'a'
                return char('a'+i);
        
            }
        }
        return 'a';
    }
};