class Solution {
public:
  int minimumLength(string s) {
    vector<int> count(26, 0);
    for (auto c : s){
      int &cnt = count[c-'a'];
      cnt++;
      if (cnt >= 3)
        cnt = 1;
    }
    int ans = 0;
    for (auto cnt : count)
      ans += cnt;
    return (ans);
  }
};