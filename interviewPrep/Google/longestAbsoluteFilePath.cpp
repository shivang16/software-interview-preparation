struct pathData {
    int totalLen;
    int depth;
    pathData(int t, int d) : totalLen(t), depth(d) {}
};

class Solution {
public:
    int lengthLongestPath(string input) {
        
        // Because the filesystem is hierarchial structure in nature,
        // I decide to use a stack to help me traverse through every
        // subdirectory and file. 
        // Once I decide to do push, I push two pieces of information.
        // 1. the total length of the absolute path to the current subdirectory, including the parent directory and '/'.
        //    In this question, the file names and directory names are not important, but their lengths.
        // 2. the depth of the current subdirectory (i.e. the number of '\t' before each file or directory name).
        // I also defined the pathData structure to make my code more readable.
        stack<pathData> filesys;
        int i = 0, answer = 0;
        
        while (i < input.size()) {
            int fileDirLen = 0, depth = 0;
            bool isFile = false;
            
            // Based upon the description and constrains, '\n' implies the end of the name of a file or directory.
            // Also, the number of '\t' implies the depth of a file or subdirectory.
            // Other characters ('\t', '.', ' ', and digits) are for the name of a file or directory.
            // Keep this idea in mind and this question becomes much more easier.
            
            // Count the number of '\t' to know the depth of the following directory or file.
            while (i < input.size() && input[i] == '\t') {
                ++depth;
                ++i;
            } // end of while-loop
            
            // At this moment, i points to the first character of a file name or directory name.
            
            // Count the length of file name or directory name.
            // Also decide whether this is a directory or a file.
            while (i < input.size() && input[i] != '\n') {
                ++fileDirLen;
                if (input[i] == '.') {
                    // Becase I find a '.', this is a file.
                    isFile = true;
                }
                ++i;
            } // end of while-loop
            
            // At this moment, i points to the '\n' right after the file or directory I have
            // parsed in the secnod inner while-loop.
            
            // Skip the '\n' and let i point to '\t'.
            // In next iteration of the outer while-loop, I can decide the depth of next directory or file
            // by counting the number of '\t', which is the job of the first inner while-loop.
            ++i;
            
            // If the depth on the top of the stack (filesys) is greater than or equal to that of 
            // current directory or file, do pop until the stack is empty or the top of the stack
            // have less depth.
            while (!filesys.empty() && filesys.top().depth >= depth) {
                filesys.pop();
            }
            
            if (isFile == false) {
                // This is a directory append a '/'. 
                ++fileDirLen;
            }
            
            if (filesys.empty()) {
                // The stack (filesys) is empty.
                // Just push the two pieces of information.
                filesys.push({fileDirLen, depth});
            } else {
                // The stack (filesys) is not empty.
                // Accumulate the length of the absolute path and do push.
                filesys.push({filesys.top().totalLen + fileDirLen, depth});
            }
            
            if (isFile == true) {
                // This is a file.
                // Try to find the longest absolute file path.
                answer = max(answer, filesys.top().totalLen);
            }
        } // end of while-loop
        
        return answer;
    }
};