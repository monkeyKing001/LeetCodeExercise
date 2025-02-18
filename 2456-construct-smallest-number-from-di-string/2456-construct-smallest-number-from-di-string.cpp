class Solution {
public:
  bool find = false;
  string answer;
  void rec(int idx, string &pattern, string &ans, unordered_set<char> &digits){
    if (find) return;
    if (idx == pattern.size()){
      answer = ans;
      //cout << "found answer : " << answer << "\n";
      find = true;
    }
    char start = pattern[idx] == 'I' ? ans[idx] + 1 : '1'; 
    char end = pattern[idx] == 'I' ? '9' : ans[idx] - 1; 
    //cout
    //  << "cur idx, ans : "
    //  << idx
    //  << ", "
    //  << ans
    //  << "\n";
    for (char d = start; d <= end; d++){
      if (!digits.contains(d)){
        ans.push_back(d);
        digits.insert(d);
        rec(idx + 1, pattern, ans, digits);
        digits.erase(d);
        ans.pop_back();
      }
    }
  }

  string smallestNumber(string pattern) {
    string ans;
    ans.reserve(pattern.size());
    unordered_set<char> digits;
    for (char d = '1'; d <= '9'; d++){
      ans.push_back(d);
      digits.insert(d);
      rec(0, pattern, ans, digits);
      ans.pop_back();
      digits.erase(d);
    }
    return (answer);
  }
};