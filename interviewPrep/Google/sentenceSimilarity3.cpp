class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque <string> dq1,dq2;
        stringstream s1(sentence1), s2(sentence2);
        string word1,word2;
        while(s1>>word1){
            dq1.push_back(word1);
        }


        while(s2>>word2){
            dq2.push_back(word2);
        }

        while(!dq1.empty() && !dq2.empty() && dq1.front()==dq2.front()){
            dq1.pop_front();
            dq2.pop_front();
        }

        while(!dq1.empty() && !dq2.empty() && dq1.back()==dq2.back()){
            dq1.pop_back();
            dq2.pop_back();
        }
        
        return (dq1.empty() || dq2.empty());
    }
};