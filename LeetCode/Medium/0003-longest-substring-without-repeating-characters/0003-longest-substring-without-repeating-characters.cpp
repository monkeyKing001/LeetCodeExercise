class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int l = 0;
      int r = l + 1;
      int sol = 0;
      set<char> char_s;
      while (l < s.size()) {
        char_s.clear();
        char_s.insert(s[l]);
        r = l + 1;
        while (r < s.size() && !char_s.contains(s[r])) {
          char_s.insert(s[r]);
          r++;
        }
        sol = max(sol, r - l);
        l = l + 1;
      }
      return sol;
    }
};