// https://leetcode.com/problems/find-and-replace-in-string/description
class Solution {
public:
    static bool comparator(pair <int,pair <string,string>> &p1,  pair <int,pair <string,string>> &p2){
        return p1.first < p2.first;
    }
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector <pair <int,pair <string,string>>> v;
        for(int i=0;i<indices.size();i++)
            v.push_back({indices[i],{sources[i],targets[i]}});
        sort(v.begin(),v.end(),comparator);
        int prevInd = 0;
        for(auto i:v){
            int ind = i.first;
            string source = i.second.first;
            string target = i.second.second;
            if(s.substr(ind+prevInd,source.length())==source){
                s.replace(ind+prevInd,source.length(),target);
                prevInd+=(target.length()-source.length());
            }
        }
        return s;
    }
};