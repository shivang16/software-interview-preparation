class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector <int> ans;
        map <int,int> M;
        for(auto i:flowers){
            M[i[0]]++;
            M[i[1]+1]--;
        }

        int count = 0;
        map <int,int> helper;
        for(auto i:M){
            count+=i.second;
            helper[i.first] = count;
            // cout << i.first << " " << i.second << " " << count << endl;
        }
        for(auto i:people){
            auto ptr = helper.lower_bound(i);
            // cout << ptr->first << endl;
            if(ptr->first==i){
                ans.push_back(ptr->second);
            }else{
                if(ptr==helper.begin())
                    ans.push_back(0);
                else
                    ans.push_back(prev(ptr)->second);
            }
        }
        return ans;
    }
};