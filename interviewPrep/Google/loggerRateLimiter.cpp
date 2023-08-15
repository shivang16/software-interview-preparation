using namespace std;
class Logger {
public:
    /**
     * @param timestamp: Timestamp
     * @param message: Message
     * @return: Whether the log can be printed
     */
    unordered_map <string,int> M;
    bool couldPrintMessage(int timestamp, string &message) {
        if(M.find(message)==M.end()){
            M[message] = timestamp;
            return true;
        }else{
            if(timestamp-M[message]<10)
                return false;
            else{
                M[message] = timestamp;
                return true;
            }
        }
        // --- write your code here ---
    }
};
