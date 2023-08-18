class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int i, j, count;
        if(n==1 && trust.size()==0)
        {
            return 1;
        }
        for(i=0 ; i<trust.size() ; i++)
        {
            count=0;
            for(j=0 ; j<trust.size() ; j++)
            {
                if(trust[j][1]==trust[i][1])
                {
                    count++;
                }
                if(trust[j][0]==trust[i][1])
                {
                    count=0;
                    break;
                }
            }
            if(count==n-1 && n!=1)
            {
                return trust[i][1];
            }
        }
        return -1;
    }
};