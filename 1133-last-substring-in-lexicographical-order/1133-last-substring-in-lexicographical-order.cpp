class Solution {
public:
    // Function to find the lexicographically largest substring of 's'
    string lastSubstring(string s) {
        int strSize = s.size();      // The size of the input string
        int startIndex = 0;          // The starting index of the current candidate for the result
        int compareStart = 1;
        int offset = 0;
        while (compareStart + offset < s.size()){
          if (s[startIndex + offset] == s[compareStart + offset])
            offset++;
          else if (s[startIndex + offset] < s[compareStart + offset]){
            startIndex = max(startIndex + offset + 1, compareStart);
            offset = 0;
            if (startIndex >= compareStart)
              compareStart = startIndex + 1;
          }
          else{
            compareStart += offset + 1;
            offset = 0;
          }
        }
        // Return the substring from 'startIndex' to the end of the string,
        // as it's the lexicographically largest substring
        return s.substr(startIndex);
    }
};
