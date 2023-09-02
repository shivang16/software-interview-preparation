class Solution {
    bool found;
    vector<double> nums;
    char ops[4] = {'+', '-', '*', '/'};
    const double eps = 1e-9;
    
public:
    double calc(double x, double y, char op) {
        if (op == '+') return x + y;
        else if (op == '-') return x - y;
        else if (op == '*') return x * y;
        else return x / y;
    }
    
    vector<double> getEvaluations(int l, int r) {
        if (found) return {}; // If an evaluation == 24 been already found, no need to continue
        if (l == r) return {nums[l]}; // As if we put parentheses around a single number, so its evalution is the number itself

        vector<double> ret;
        // Trying all the ways we could split the current range into two subranges
        // for example: if cards = {1,2,3,4} & l = 1, r = 3
        // all the possible splits are: {(2), (3,4)}, {(2,3), (4)}
        for (int i = l; i < r; i++) { 
            // get all possiple evaluations from left & right subranges 
            auto resL = getEvaluations(l, i), resR = getEvaluations(i+1, r);

            // getting all possilbe evaluations by using an operation between left & right subranges
            for (auto x : resL){
                for (auto y : resR) {
                    for (char op : ops) {
                        if (op == '/' && y == 0) continue; // avoid dividing by 0
                        
                        ret.push_back(calc(x, y, op));
                        
                        // checking if the whole range evaluation resulted to 24
                        // because we could get 24 in a sub range but it can't be an answer
                        if (l == 0 && r == 3) found |= (abs(ret.back() - 24.0) < eps);
                    }
                }
            }
        }

        return ret;
    }

    bool judgePoint24(vector<int>& cards) {
        for (auto x : cards) nums.push_back(x * 1.0); // converting to double, for better precision
		
        sort(nums.begin(), nums.end());
        do {
            found = false;
            getEvaluations(0, 3);
            if (found) return true;
        } while (next_permutation(nums.begin(), nums.end()));

        return false;
    }
};