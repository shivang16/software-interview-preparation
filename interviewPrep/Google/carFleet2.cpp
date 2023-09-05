// https://leetcode.com/problems/car-fleet-ii/description/s
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double>ans(cars.size(),-1);
        stack<int>st;
        for(int i=cars.size()-1; i >= 0; --i){
            //car ahead of current car is faster?
            // We are not worry about the cars on the left because no matter what the speed of previous cars are 
            // They will at some point will colide with current car and their speed will decrease and since our current car cannot catch the next car
            // Previous cars will never be able to catch the next cars, so we will pop
            while(!st.empty() and cars[st.top()][1] >= cars[i][1]){
                st.pop();
            }

            while(!st.empty()){
                // Now if our current car collides with next car (whose collision time is more) -> Then in this case we have successful collision because
                // next car's speed will not change, so there will be no effect on next collision time.
                double clash_time=(double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
                if(ans[st.top()] == -1 or clash_time <= ans[st.top()]){
                    ans[i]=clash_time;
                    break;
                }
                st.pop();

            }
            st.push(i);
        }
        return ans;

    }
};