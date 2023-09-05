
class Solution {
public:
    /**
     * @param sweetness: an integer array
     * @param k: an integer
     * @return:  return the maximum total sweetness of the piece
     */
    bool canBeDivided(vector <int>& arr,int k,int val){
        int sum = 0;
        int count = 0;
        for(auto i:arr){
            sum+=i;
            if(sum>=val){
                count++;
                sum = 0;
            }
        }
        return count>=k;
    }
    int maximizeSweetness(vector<int> &sweetness, int k) {
        int low = *min_element(sweetness.begin(),sweetness.end());
        int high = 0;
        for(auto i:sweetness) high+=i;

        int ans = 0;
        while(high>=low){
            int mid = (high+low)/2;
            // cout << low << " " << mid << " " << high << " " << ans << endl;
            if(canBeDivided(sweetness,k+1,mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
        // write your code here
    }
};