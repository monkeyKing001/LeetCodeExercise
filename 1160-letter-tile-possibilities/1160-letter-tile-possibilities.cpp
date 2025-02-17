class Solution {
public:

  void rec(vector<int> &dp, int &ans){
    for (int i = 0; i < 26; i++){
      if (dp[i]){
        dp[i]--, ans++;
        rec(dp, ans);
        dp[i]++;
      }
    }
  }

  int numTilePossibilities(string tiles) {
    int ans = 0;
    vector<int> dp(26, 0);
    for (auto c: tiles)
      dp[c - 'A']++;
    rec(dp, ans);
    return (ans);
  }
};