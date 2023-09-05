// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowCount = 0;
        int low = 0,high = 0;
        int ans = 0;
        while(high<n){
            if(isVowel(s[high])){
                vowCount++;
            }
            if(high-low+1==k){
                // cout << low << " " << high << " " << vowCount << endl;
                ans = max(ans,vowCount);
                if(isVowel(s[low]))
                    vowCount--;
                low++;
            }
            high++;
        }
        return ans;
    }
};