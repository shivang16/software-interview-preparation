vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue <int> Q;
    for(auto i:A){
        Q.push(i);
    }
    vector <int> ans;
    for(int i=0;i<B;i++){
        ans.push_back(Q.top());
        Q.pop();
    }
    return ans;
}
