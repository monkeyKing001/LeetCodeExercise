using pos = pair<int, int>;
class Solution {
public:
  int m, n;

  int minPathSum(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 1 << 20));
    dp[m - 1][n - 1] = grid[m - 1][n - 1];
    for (int i = m - 1; i >= 0; i--){
      for (int j = n - 1; j >= 0; j--){
        int cur_cost = dp[i][j];
        if (i > 0) dp[i - 1][j] = min(dp[i - 1][j], cur_cost + grid[i - 1][j]);
        if (j > 0) dp[i][j - 1] = min(dp[i][j - 1], cur_cost + grid[i][j - 1]);
      }
    }
    return (dp[0][0]);
  }
};