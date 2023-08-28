class Solution {
public:
    int dp[2000][2000];
    bool getAns(vector <int>& stones,int ind,int k){
        if(ind==stones.size()-1) return true;
        if(dp[ind][k]!=-1) return dp[ind][k];
        bool ans = false;
        for(int i=ind+1;i<stones.size();i++){
            if(stones[i] > stones[ind]+k+1){
                break;
            }
            else if(stones[i] == stones[ind]+k+1){
                ans |= getAns(stones,i,k+1);
            }else if(stones[i] == stones[ind]+k){
                ans |= getAns(stones,i,k);
            }else if(stones[i] == stones[ind]+k-1){
                ans |= getAns(stones,i,k-1);
            }
        }
        return dp[ind][k] = ans;
    }
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return getAns(stones,0,0);
    }
};