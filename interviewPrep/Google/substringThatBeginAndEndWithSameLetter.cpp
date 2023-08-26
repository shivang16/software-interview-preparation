int nC2(int n){
    return n*(n-1)/2;
}
int numberOfSubstringThatBeginAndEndWithSameLetter(string s){
    unordered_map <char,int> M;
    for(auto i:s) M[i]++;
    int ans = 0;
    for(auto i:M){
        if(i.second>1) ans+=nC2(i.second);
    }
    return s.size()+ans;
}

int main() {
    
    cout << numberOfSubstringThatBeginAndEndWithSameLetter("abcba") << endl;
    
    cout << numberOfSubstringThatBeginAndEndWithSameLetter("abacad") << endl;
    
    cout << numberOfSubstringThatBeginAndEndWithSameLetter("a") << endl;
}