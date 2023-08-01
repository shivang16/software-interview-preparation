vector<int> MinimumCoins(int n)
{
    vector <int> v = {1000,500,100,50,20,10,5,2,1};
    vector <int> ans;
    int i = 0;
    while(n>0){
        if(n>=v[i]){
            ans.push_back(v[i]);
            n-=v[i];
        }else{
            i++;
        }
    }
    return ans;
    // Write your code here
}