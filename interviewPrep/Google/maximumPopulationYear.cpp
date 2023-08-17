class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int population[2051];
        memset(population,0,sizeof(population));
        for(auto i:logs){
            population[i[0]]++;
            population[i[1]]--;
        }
        int mx = 0;
        int ans;
        int crnt = 0;
        for(int i=1950;i<2050;i++){
            crnt+=population[i];
            if(crnt>mx){
                mx = crnt;
                ans = i;
            }
        }
        return ans;
    }
};