// https://leetcode.com/problems/rings-and-rods/
class Solution {
public:
    int countPoints(string ring) {
        unordered_map <int,unordered_set<char>> M;
        for(int i=0;i<ring.length()-1;i++){
            char col = ring[i];
            int num = ring[i+1]-'0';
            if(M.find(num)==M.end()){
                unordered_set <char> s;
                M[num] = s;
            }
            M[num].insert(col);
            i++;
        }
        int ans = 0;
        for(auto i:M)
            if(i.second.size()==3)
                ans++;
        return ans;
    }
};