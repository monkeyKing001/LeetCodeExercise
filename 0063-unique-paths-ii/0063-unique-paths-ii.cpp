class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& o) {
    int m = o.size();
    int n = o[0].size();
    if (o[0][0]) return (0);
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        if (o[i][j]) dp[i][j] = 0;
        else{
          if (i > 0) dp[i][j] += dp[i - 1][j];
          if (j > 0) dp[i][j] += dp[i][j - 1];
        }
        //cout << dp[i][j] << " ";
      }
      //cout << "\n";
    }
    return (dp[m - 1][n - 1]);
  }
};