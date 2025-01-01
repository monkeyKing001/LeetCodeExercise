class Solution {
public:
  int maxScore(string s) {
    vector<int> zeroDp(s.size(), 0);
    vector<int> oneDp(s.size(), 0);
    int ans = 0;
    if (s[0] == '0')
      zeroDp[0] = 1;
    else
      oneDp[0] = 1;
    for (int i = 1 ; i < s.size(); i++){
      char c = s[i];
      if (c == '0')
        zeroDp[i]++;
      else 
        oneDp[i]++;
      zeroDp[i] += zeroDp[i - 1];
      oneDp[i] += oneDp[i - 1];
    }
    for (int i = 0; i < s.size() - 1; i++){
      int left_score = zeroDp[i];
      int right_score = oneDp.back() - oneDp[i];
      ans = max(left_score + right_score, ans);
    }
    return (ans);
  }
};