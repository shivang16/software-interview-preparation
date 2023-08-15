// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map <string,int> Mp;
        for(auto i:targetWords){
            string x = i;
            sort(x.begin(),x.end());
            Mp[x]++;
        }
        // for(auto i:Mp)
        //     cout << i.first << " " << i.second << endl;
        int ans = 0;
        for(auto i:startWords){
            // cout << i << endl;
            vector <int> temp(26,0);
            for(auto j:i)
                temp[j-'a']++;
            for(int j=0;j<26;j++){
                char c = 'a'+j;
                if(temp[j]==0){
                    string x = i;
                    x = x+c;
                    sort(x.begin(),x.end());
                    // cout << c << " " << x << " " << ans << endl;
                    if(Mp.find(x)!=Mp.end()){
                        ans+=Mp[x];
                        Mp.erase(x);
                    }
                }
            }
        }
        return ans;
    }
};