// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/submissions/
class Solution {
public:
    string tictactoe(vector<vector<int>>& M) {
        int A[4][4];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                A[i][j] = 0;
        }
        if(M.size()==0)
            return "Draw";
        int n = M.size(),m = M[0].size();
        bool chance = true;
        for(int i=0;i<n;i++)
        {
            if(chance)
                A[M[i][0]][M[i][1]] = 4;
            else
                A[M[i][0]][M[i][1]] = 3;
            chance = !chance;
        }
        //row sum
        for(int i=0;i<3;i++)
        {
            int sum = 0;
            for(int j=0;j<3;j++)
            {
                sum+=A[i][j];
            }
            A[i][3] = sum;
        }
        for(int i=0;i<3;i++)
        {
            int sum = 0;
            for(int j=0;j<3;j++)
            {
                sum+=A[j][i];
            }
            A[3][i] = sum;
        }
        int d1 = A[0][0]+A[1][1]+A[2][2];
        int d2 = A[0][2]+A[1][1]+A[2][0];
        int x = 12;
        if(A[3][0]==x || A[3][1]==x || A[3][2]==x || A[0][3]==x || A[1][3]==x || A[2][3]==x || d1==x || d2==x)
            return "A";
        x = 9;
        if(A[3][0]==x || A[3][1]==x || A[3][2]==x || A[0][3]==x || A[1][3]==x || A[2][3]==x || d1==x || d2==x)
            return "B";
        if(M.size()<9)
            return "Pending";
        else
            return "Draw";
            
        
        
            
    }
};