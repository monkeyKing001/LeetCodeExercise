#define CHAR first
#define COUNT second
class Solution {
public:
  bool canConstruct(string s, int k) {
    unordered_map<char, int> count;
    int total_count = s.size();
    if (total_count < k)
      return false;
    for (auto c : s)
      count[c - 'a']++;
    for (auto info : count){
      if (info.COUNT % 2 == 1)
        k--;
      if (k < 0)
        return false;
    }
    return (true);
  }
};