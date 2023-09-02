class Solution {
public:
    /**
     * @param words1: a list of string
     * @param words2: a list of string
     * @param pairs: a list of string pairs
     * @return: return a boolean, denote whether two sentences are similar or not
     */
    bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        // write your code here
        
        if(words1.size()!=words2.size()) return false;
        set <pair<string,string>> St;
        for(auto i:pairs){
            St.insert({i[0],i[1]});
            St.insert({i[1],i[0]});
        }
        for(int i=0;i<words1.size();i++){
            if(words1[i]==words2[i])
                continue;
            if(St.find({words1[i],words2[i]})==St.end() && St.find({words2[i],words1[i]})==St.end())
                return false;
        }
        return true;
    }
};