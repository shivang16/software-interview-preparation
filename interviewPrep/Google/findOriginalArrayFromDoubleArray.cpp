// https://leetcode.com/problems/find-original-array-from-doubled-array/description/
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector <int> ans;
        map <int,int> M;
        int zCount = 0;
        for(auto i:changed){
            if(i==0)
                zCount++;
            else
                M[i]++;        
        }
        
        if(zCount%2)
            return ans;
        zCount/=2;
        while(zCount-->0){
            ans.push_back(0);
        }
        for(auto i:M){
            if(i.second>0){
                // cout << i.first << " " << i.second << endl;
                vector <int> temp;
                if(M.find(i.first*2)==M.end()){
                    return temp;
                }else{
                    if(i.second-M[i.first*2]>0)
                        return temp;
                    else{
                        M[i.first*2]-=i.second;
                        while(i.second--)
                            ans.push_back(i.first);
                    }
                }
            }
        }
        return ans;
    }
};