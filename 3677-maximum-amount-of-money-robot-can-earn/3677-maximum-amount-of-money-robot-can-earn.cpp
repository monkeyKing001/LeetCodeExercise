using info = pair<pair<int, int>, pair<int, int>>;//<r, c>, <cur_coins, chance to neutralize>
class Solution {
public:
  int dr[2] = {1, 0};
  int dc[2] = {0, 1};
  int maximumAmount(vector<vector<int>>& coins) {
    int m = coins.size();
    int n = coins[0].size();
    int ans = INT_MIN;
    int MIN_COST = 500 * 500 * 1000 * -1;
    vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int>(3, MIN_COST)));
    dp[0][0][2] = coins[0][0];
    if (coins[0][0] < 0)
        dp[0][0][1] = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            for (int di = 0; di < 2; di++){
                int prev_r = i - dr[di];
                int prev_c = j - dc[di];
                if (prev_r >= 0 && prev_r < m && prev_c >= 0 && prev_c < n){
                    if (coins[i][j] >= 0){
                        dp[i][j][2] = max(dp[prev_r][prev_c][2] + coins[i][j], dp[i][j][2]);
                        dp[i][j][1] = max(dp[prev_r][prev_c][1] + coins[i][j], dp[i][j][1]);
                        dp[i][j][0] = max(dp[prev_r][prev_c][0] + coins[i][j], dp[i][j][0]);
                    }
                    else{
                        dp[i][j][2] = max(dp[prev_r][prev_c][2] + coins[i][j], dp[i][j][2]);
                        dp[i][j][1] = max(dp[prev_r][prev_c][1] + coins[i][j], dp[i][j][1]);
                        dp[i][j][1] = max(dp[prev_r][prev_c][2], dp[i][j][1]);
                        dp[i][j][0] = max(dp[prev_r][prev_c][0] + coins[i][j], dp[i][j][0]);
                        dp[i][j][0] = max(dp[prev_r][prev_c][1], dp[i][j][0]);
                    }
                }
            }
            //cout 
            //    << "[ " 
            //    << dp[i][j][2]
            //    << ", "
            //    << dp[i][j][1]
            //    << ", "
            //    << dp[i][j][0]
            //    << "] ";
        }
        //cout << "\n";
    }
    ans = max(ans, dp[m - 1][n - 1][0]);
    ans = max(ans, dp[m - 1][n - 1][1]);
    ans = max(ans, dp[m - 1][n - 1][2]);
    return (ans);
  }
};