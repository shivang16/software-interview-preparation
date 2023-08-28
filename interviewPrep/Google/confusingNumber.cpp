bool isConfusingNumber(int n){
    unordered_map <char,char> M;
    M['0'] = '0';
    M['1'] = '1';
    M['6'] = '9';
    M['8'] = '8';
    M['9'] = '6';
    string s = to_string(n);
    for(auto i:s){
        if(M.count(i)==0) return false;
    }
    string t = s;
    reverse(t.begin(),t.end());
    for(int i=0;i<s.size();i++){
        if(s[i]!=M[t[i]]) return false;
    }
    return true;
}
int main() {
    cout << isConfusingNumber(69) << endl;
    cout << isConfusingNumber(89) << endl;
    cout << isConfusingNumber(11) << endl;
    cout << isConfusingNumber(6) << endl;
    cout << isConfusingNumber(98) << endl;
    
}