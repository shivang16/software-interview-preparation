class Solution {
private:
    void pushRes(vector<string> &res, deque<string> &curr, unordered_set<string> &memo) {
        while (!curr.empty()) {
            if (!memo.count(curr.front())) {
                res.push_back(curr.front());
                memo.insert(curr.front());
            }
            curr.pop_front();
        }
    }
    
    vector<string> resolve(string &exp, int &i) {
        vector<string> res;
        deque<string> curr;
        unordered_set<string> memo;
        
        while (i < exp.size()) {
            bool endLoop = false;
            switch(exp[i]) {
                case '{': // recursively obtain the string vector of next section
                {
                    vector<string> temp = resolve(exp, ++i);
                    if (curr.empty()) curr.push_back("");
                    int currSize = curr.size();
                    while (currSize-- > 0) {
                        for (string &eachTemp : temp) {
                            curr.push_back(curr.front() + eachTemp);
                        }
                        curr.pop_front();
                    }
                    break;
                }
                case '}': // end current section
                    endLoop = true;
                    break;
                    
                case ',': // push curent buffered strings into result
                    pushRes(res, curr, memo);
                    break;

                default: // push the character into curr buffered strings
                    if (curr.empty()) curr.push_back("");
                    for (string &eachCurr : curr) {
                        eachCurr += exp[i];
                    }
                    break;
            }
            if (endLoop) break;
            ++i;
        }
        
        pushRes(res, curr, memo);
        return res;
    }
    
public:
    vector<string> braceExpansionII(string exp) {
        int i = 0;
        vector<string> res = resolve(exp, i);
        sort(res.begin(), res.end());
        return res;
    }
};