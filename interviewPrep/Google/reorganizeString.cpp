class Solution {
public:
    string reorganizeString(string s) {
        priority_queue <pair <int,char>> Q;
        unordered_map <char,int> M;
        for(auto i:s)
            M[i]++;
        for(auto i:M){
            Q.push({i.second,i.first});
        }
        string ans = "";
        while(!Q.empty()){
            char c = Q.top().second;
            int count = Q.top().first;
            Q.pop();
            if(ans==""){
                ans+=c;
                count--;
                if(count>0)
                    Q.push({count,c});
            }else{
                int lastChar = ans[ans.size()-1];
                if(lastChar==c){
                    if(Q.empty()) return "";
                    char secondChar = Q.top().second;
                    int count1 = Q.top().first;
                    Q.pop();
                    ans+=secondChar;
                    count1--;
                    if(count1>0)
                        Q.push({count1,secondChar});
                    Q.push({count,c});
                }else{
                    ans+=c;
                    count--;
                    if(count>0)
                        Q.push({count,c});
                }
            }
        }

        return ans;
    }
};