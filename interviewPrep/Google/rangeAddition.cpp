class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector <int> arr(length,0);
        for(auto i:updates){
            arr[i[0]]+=i[2];
            if(i[1]<length-1)
                arr[i[1]+1]-=i[2];
        }
        // for(int i=0;i<length;i++)
        //     cout << arr[i] << endl;
        for(int i=1;i<length;i++)
            arr[i]+= arr[i-1];
        return arr;
        // Write your code here
    }
};