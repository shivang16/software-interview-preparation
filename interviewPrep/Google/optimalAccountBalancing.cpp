#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        
        for (auto& t : transactions) {
            balance[t[0]] -= t[2];
            balance[t[1]] += t[2];
        }
        
        vector<int> debts;
        for (auto& b : balance) {
            if (b.second != 0) {
                debts.push_back(b.second);
            }
        }
        
        return minTransfersDFS(0, debts);
    }
    
    int minTransfersDFS(int start, vector<int>& debts) {
        while (start < debts.size() && debts[start] == 0) {
            start++;
        }
        
        if (start == debts.size()) {
            return 0;
        }
        
        int minTransactions = INT_MAX;
        
        for (int i = start + 1; i < debts.size(); i++) {
            if (debts[i] * debts[start] < 0) {
                debts[i] += debts[start];
                minTransactions = min(minTransactions, 1 + minTransfersDFS(start + 1, debts));
                debts[i] -= debts[start];
            }
        }
        
        return minTransactions;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> t1 = {{0, 1, 10}, {2, 0, 5}};
    cout << solution.minTransfers(t1) << endl;  // Output: 2

    vector<vector<int>> t2 = {{0, 1, 10}, {1, 0, 1}, {1, 2, 5}, {2, 0, 5}};
    cout << solution.minTransfers(t2) << endl;  // Output: 2

    return 0;
}
