class Solution {
public:
    bool judge_nice(string str){
      unordered_set<char> lower_set;
      unordered_set<char> upper_set;
      for (int i = 0; i < str.size(); i++){
        char cur_char = str[i];
        if (cur_char == tolower(cur_char))
          lower_set.insert(cur_char);
        else if (cur_char == toupper(cur_char))
          upper_set.insert(cur_char);
      }
      for (int i = 0; i < str.size(); i++){
        char cur_char = str[i];
        if (lower_set.contains(tolower(cur_char)) && upper_set.contains(toupper(cur_char)))
          continue;
        else
          return false;
      }
      cout << str <<"\n";
      return true;
    }
    string longestNiceSubstring(string s) {
      string sol = "";
      for (int i = 0; i < s.size(); i++){
        for (int j = i + 1; j < s.size(); j++){
          string sbstr = s.substr(i, j - i  + 1);
          if (judge_nice(sbstr) && sol.size() < sbstr.size())
            sol = sbstr;
        }
      }
      return (sol);
   }
};