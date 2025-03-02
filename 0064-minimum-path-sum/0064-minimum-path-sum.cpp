using pos = pair<int, int>;
class Solution {
public:
  int m, n;
  int dr[2] = {1, 0};
  int dc[2] = {0, 1};

  int rec(vector<vector<int>> &grid, vector<vector<int>> &dp, pos p){
    auto [r, c] = p;
    if (r == m - 1 && c == n - 1) dp[r][c] = grid[r][c];
    int &result = dp[r][c];
    if (result != -1) return result;
    result = 1e8;
    for (int di = 0; di < 2; di++){
      int next_r = r + dr[di];
      int next_c = c + dc[di];
      if (next_r < m && next_c < n) 
        result = min(result, rec(grid, dp, {next_r, next_c}) + grid[r][c]);
    }
    return (result);
  }

  int minPathSum(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 1 << 20));
    dp[m - 1][n - 1] = grid[m - 1][n - 1];
    //vector<vector<int>> dp = grid;
    for (int i = m - 1; i >= 0; i--){
      for (int j = n - 1; j >= 0; j--){
        int cur_cost = dp[i][j];
        if (i > 0)
          dp[i - 1][j] = min(dp[i - 1][j], cur_cost + grid[i - 1][j]);
        if (j > 0)
          dp[i][j - 1] = min(dp[i][j - 1], cur_cost + grid[i][j - 1]);
      }
    }
    //int ans = rec(grid, dp, {0, 0});
    return (dp[0][0]);
  }
};