class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int A[10],B[10];
        for(int i=0;i<10;i++)
            A[i]=0,B[i]=0;
        int n = secret.size();
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i])
                bulls++;
            else{
                A[secret[i]-'0']++;
                B[guess[i]-'0']++;
            }
        }

        int cows = 0;
        for(int i=0;i<10;i++){
            if(A[i]>=B[i])
                cows+=B[i];
            else
                cows+=A[i];
        }
        return to_string(bulls)+'A'+to_string(cows)+'B';

    }
};