// https://www.interviewbit.com/problems/anagrams/
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector <vector <int> > ans;
    map <vector <int>,vector <int> > M;
    for(int i=0;i<A.size();i++){
        vector <int> temp(26,0);
        for(int j=0;j<A[i].length();j++){
            temp[A[i][j]-'a']++;
        }
        if(M.find(temp)==M.end()){
            vector <int> x;
            x.push_back(i+1);
            M[temp] = x; 
        }else{
            M[temp].push_back(i+1);
        }
    }
    for(auto i:M){
        ans.push_back(i.second);
    }
    return ans;
}
