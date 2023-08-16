// https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/description/
class Solution {
public:
    bool match(string x,string y){
        int l = x.size();
        bool ans = true;
        for(int i=0;i<l;i++){
            if(!(x[i]==y[i] || x[i]==' '))
                ans = false;
        }
        if(ans) return true;
        reverse(x.begin(),x.end());
        for(int i=0;i<l;i++){
            if(!(x[i]==y[i] || x[i]==' '))
                return false;
        }
        
        return true;
    }
    bool check(vector <string> &can,string &word){
        for(auto i:can){
            if(match(i,word))
                return true;
        }
        return false;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        vector <string> candidate;
        int m = board.size(), n = board[0].size();
        int l = word.size();
        
        //Find horizontal
        for(int i=0;i<m;i++){
            string temp = "";
            int j = 0;
            while(j<n){
                if(board[i][j]=='#'){
                    if(temp.size()==l){
                        candidate.push_back(temp);
                    }
                    temp = "";
                }else{
                    temp+=board[i][j];
                }
                j++;
            }
            if(temp.size()==l){
                candidate.push_back(temp);
            
            }
        }

        //Find vertical
        for(int i=0;i<n;i++){
            string temp = "";
            int j = 0;
            while(j<m){
                if(board[j][i]=='#'){
                    if(temp.size()==l){
                        candidate.push_back(temp);
                    }
                    temp = "";
                }else{
                    temp+=board[j][i];
                }
                j++;
            }
            if(temp.size()==l){
                candidate.push_back(temp);
            
            }
        }

        return check(candidate,word);
    }
};