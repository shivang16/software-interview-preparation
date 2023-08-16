class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    // Edge case: If the array is empty, return an empty string
    if (strs.empty()) {
        return "";
    }

    // Sort the array so that we can compare the strings in order
    sort(strs.begin(), strs.end());

    // Get the first and last strings in the sorted array
    string first = strs[0];
    string last = strs[strs.size() - 1];

    // Initialize a variable to store the common prefix
    string prefix = "";

    // Iterate over the characters in the first string
    for (int i = 0; i < first.size(); i++) {
        // If the characters in the first and last strings match, add it to the prefix
        if (first[i] == last[i]) {
            prefix += first[i];
        }
        // If the characters don't match, we've found the longest common prefix
        else {
            break;
        }
    }

    // Return the common prefix
    return prefix;
}
};