class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int n = values.size();
    int sol = INT_MIN;
    vector<int> dp(n, INT_MIN);
    dp.back() = values.back() - (n - 1);
    for (int i = n - 2; i >= 0; i--){
      sol = max(values[i] + i + dp[i + 1], sol);
      dp[i] = max(values[i] - i, dp[i + 1]);
    }
    return (sol);
  }
};