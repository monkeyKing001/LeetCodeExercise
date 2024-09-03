class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      int min_len = INT_MAX;
      string sol = "";
      for (int i = 0; i < strs.size(); i++)
        min_len = min((int)strs[i].size(), min_len);
      bool finished = false;
      for (int j = 0; j < min_len && !finished; j++){
        char cur_chr = strs[0][j];
        for (int i = 0; i < strs.size() && !finished; i++){
          if (strs[i][j] != cur_chr)
            finished = true;
          if (i == strs.size() - 1 && !finished)
            sol.push_back(cur_chr);
        }
      }
      return (sol);
    }
};