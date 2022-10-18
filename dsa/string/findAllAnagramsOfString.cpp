class Solution {
public:
    bool isAnagram(vector <int> A,vector <int> B){
        for(int i=0;i<26;i++)
            if(A[i]!=B[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector <int> ans;
        int n1=s.length();
        int n2=p.length();
        if(n1<n2)
            return ans;
        vector <int> M1(26,0);
        vector <int> M2(26,0);
        for(auto i:p)
            M2[i-'a']++;
        int l=0,r=0;
        while(r<n1){
            // cout <<l << " " << r << endl;
            if(r<n2){
                // cout << "foo\n";
                M1[s[r]-'a']++;
                r++;
            }else{
                // cout << "bar\n";
                if(isAnagram(M1,M2))
                    ans.push_back(l);
                M1[s[l]-'a']--;
                M1[s[r]-'a']++;
                l++;
                r++;
            }
            
        }
        if(isAnagram(M1,M2))
                    ans.push_back(l);
        return ans;
        
    }
};