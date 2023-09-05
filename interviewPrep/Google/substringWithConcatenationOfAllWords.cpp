// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
class Solution {
public:
    bool checker(string s,unordered_map <string,int> WordMap,int wordSize,int low,int high){
        int l=0,h=0;
        // cout << s << " " << low << " " << high << endl;
        string x = "";
        for(int i=low;i<=high;i+=wordSize){
            x = s.substr(i,wordSize);
            WordMap[x]--;
        }
        for(auto i:WordMap){
            if(i.second!=0) return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        unordered_map <string,int> WordMap;
        int subSize = 0;
        int wordSize = 0;
        for(auto i:words){
            WordMap[i]++;
            subSize+=i.size();
            wordSize=i.size();
        }

        int low = 0, high = 0;
        string temp = "";
        vector <int> ans;
        while(high<n){
            temp+=s[high];
            if(high-low+1==subSize){
                if(checker(temp,WordMap,wordSize,low,high)){
                    ans.push_back(low);
                }
                low++;    
            }
            high++;
        }
        return ans;
    }
};