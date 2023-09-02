// https://www.lintcode.com/problem/879/?fromId=207&_from=collection
class Solution {
public:
    /**
     * @param n: a integer, denote the number of teams
     * @return: a string
     */
    string findContestMatch(int n) {
        deque <string> dq;
        for(int i=1;i<=n;i++)
            dq.push_back(to_string(i));
        while(dq.size()!=1){
            queue <string> temp;
            while(dq.size()){
                string first = dq.front();
                string last = dq.back();
                dq.pop_front(); dq.pop_back();
                string finalString = '('+first+','+last+')';
                temp.push(finalString);
            }   
            while(temp.size()){
                dq.push_back(temp.front());
                temp.pop();
            }
        }
        return dq.front();
        // write your code here
    }
};