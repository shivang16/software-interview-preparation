// https://leetcode.com/problems/number-of-boomerangs/
class Solution {
public:
    long long dis(vector <int>& p1,vector <int> &p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for(int i=0;i<n;i++){
            unordered_map <long long,int> M;
            for(int j=0;j<n;j++){
                if(i!=j){
                    int dist = dis(points[i],points[j]);
                    M[dist]++;
                }
            }
            for(auto i:M){
                ans+= (i.second)*(i.second-1);
            }
        }    
        return ans;
    }
};