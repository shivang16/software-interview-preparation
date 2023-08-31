class ValidWordAbbr {
    string getAbbrivation(string s){
        if(s.size()<=2) return s;
        return s[0]+to_string(s.size()-2)+s[s.size()-1];
    }

    unordered_set <string> myDict;
public:
    /*
    * @param dictionary: a list of words
    */
    
    ValidWordAbbr(vector<string> dictionary) {
        // do intialization if necessary
        for(auto i:dictionary)
            myDict.insert(getAbbrivation(i));
    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    bool isUnique(string &word) {
        return myDict.find(getAbbrivation(word))==myDict.end();
        // write your code here
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */