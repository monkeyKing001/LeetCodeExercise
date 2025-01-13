class Solution {
public:
  int minimumLength(string s) {
    vector<int> count(26, 0);
    for (auto c : s){
      count[c - 'a']++;
      if (count[c - 'a'] >= 3)
        count[c - 'a'] = 1;
    }
    int ans = 0;
    for (auto cnt : count)
      ans += cnt;
    return (ans);
  }
};