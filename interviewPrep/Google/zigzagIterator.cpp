// https://www.lintcode.com/problem/540/
class ZigzagIterator {
private:
    
    queue <int> Q;
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        // do intialization if necessary
        bool chance = true;
        int i=0,j=0;
        while(i<v1.size() && j<v2.size()){
            if(chance){
                Q.push(v1[i++]);
            }else{
                Q.push(v2[j++]);
            }
            chance = !chance;
        }
        while(i<v1.size()) Q.push(v1[i++]);
        while(j<v2.size()) Q.push(v2[j++]);
        
    }

    /*
     * @return: An integer
     */
    int next() {
        int val = Q.front();
        Q.pop();
        return val;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        return Q.size();
        // write your code here
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */