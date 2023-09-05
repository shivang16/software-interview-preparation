// https://leetcode.com/problems/text-justification/description/
class Solution {
public:
    string getLine(int l,int r,vector <string>& words,int maxWidth,bool isLast){
        // cout << l << " " << r << endl;
        int totalWords = r-l+1;
        if(totalWords==0)
            return "";
        int totalTextLen = 0;
        for(int i=l;i<=r;i++)
            totalTextLen+=words[i].size();
        int totalSpaces = maxWidth-totalTextLen;
        int wordSpaces = totalSpaces;
        int whereToStop = l-1;
        if(totalWords!=1){
            wordSpaces = totalSpaces/(totalWords-1);
            if(wordSpaces*(totalWords-1)<totalSpaces){
                whereToStop = l+totalSpaces-wordSpaces*(totalWords-1);
            }
        }
        if(isLast){
            wordSpaces = 1;
            whereToStop = l-1;
        }
        // cout << totalWords << " " << totalTextLen << " " <<e totalSpaces << " " << wordSpaces << " " << whereToStop << endl;
        string line = "";
        for(int i=l;i<=r;i++){
            line+=words[i];
            int x = wordSpaces;
            while(x-->0 && totalSpaces-->0){
                line+=' ';
            }
            if(i<whereToStop){
                line+=' ';
                totalSpaces--;
            }
        }
        while(totalSpaces-->0)
            line+=' ';
        return line;

    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int spaceLen = 0, crntLen = 0;
        int left = 0, right = 0;
        int n = words.size();
        vector <string> ans;
        while(right<n){
            crntLen+=words[right].size();
            // cout << left << " " << right << " " << spaceLen << " " << crntLen << endl;
            if(crntLen+spaceLen>maxWidth){
                string line = getLine(left,right-1,words,maxWidth,false);
                ans.push_back(line);
                left = right;
                crntLen = 0;
                spaceLen = 0;
            }else if(crntLen+spaceLen==maxWidth){
                // cout << "wofbh" << endl;
                string line = getLine(left,right,words,maxWidth,false);
                ans.push_back(line);
                right++;
                left = right;
                crntLen = 0;
                spaceLen = 0;
            }else{
                spaceLen++;
                right++;
            }
        }
        if(right>=left && crntLen>0)
            ans.push_back(getLine(left,right-1,words,maxWidth,true));
        return ans;
    }
};