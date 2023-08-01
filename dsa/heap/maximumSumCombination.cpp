// https://www.interviewbit.com/problems/maximum-sum-combinations/
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector <int> ans;
    priority_queue <pair<int,pair<int,int>>> Q;
    set <pair<int,int>> S;
    Q.push({A[A.size()-1]+B[B.size()-1],{A.size()-1,B.size()-1}});
    S.insert({A.size()-1,B.size()-1});
    while(C--){
        ans.push_back(Q.top().first);
        int a = Q.top().second.first;
        int b = Q.top().second.second;
        Q.pop();
        if(S.find({a-1,b})==S.end()){
            Q.push({A[a-1]+B[b],{a-1,b}});
            S.insert({a-1,b});
        }
            
        if(S.find({a,b-1})==S.end()){
            Q.push({A[a]+B[b-1],{a,b-1}});
            S.insert({a,b-1});
        }
            
    }
    return ans;
}


/*
1 2 4 4
1 2 5 6

10 

*/