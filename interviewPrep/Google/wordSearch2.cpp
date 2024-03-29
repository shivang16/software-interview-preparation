// https://leetcode.com/problems/word-search-ii/submissions/1024138528/
struct TrieNode{
    vector<TrieNode*> children;
    bool end;
    string word;

    TrieNode(): children(26, nullptr), end(false), word(""){}
};

class Solution {
    TrieNode* root;
    vector<string> result;

    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
public:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* ptr){
        // valid position
        if (i < 0 || i >= m || j < 0 || j  >= n){
            return;
        }
        // the same letter cannot be used twice.
        if (board[i][j] == '#'){
            return;
        }
        // not a known word
        if (ptr->children[board[i][j] - 'a'] == nullptr){
            return;
        }
        // word found
        if (ptr->children[board[i][j] - 'a']->end){
            result.push_back(ptr->children[board[i][j] - 'a']->word);
            // delete this word
            ptr->children[board[i][j] - 'a']->end = false;
            // return;
        }
        // mark the letter as used, and find the next letter.
        char letter = board[i][j];
        board[i][j] = '#';
        for (const auto &dir: dirs){
            dfs(board, i + dir[0], j + dir[1], ptr->children[letter - 'a']);
        }
        // finish the search, unmark the letter.
        board[i][j] = letter;
    }

    void build_trie_tree(const vector<string> &words){
        for (const auto &word: words){
            TrieNode* cur = root;
            for (const char ch: word){
                if (cur->children[ch - 'a'] == nullptr) {
                    cur->children[ch - 'a'] = new TrieNode();
                }
                cur = cur->children[ch - 'a'];
            }
            cur->end = true;
            cur->word = word;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();

        // 1. construct the trie tree
        root = new TrieNode();
        build_trie_tree(words);

        // 2. traverse the board and use backtracking to search the words
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                dfs(board, i, j, root);
            }
        }
        return result;
    }
};