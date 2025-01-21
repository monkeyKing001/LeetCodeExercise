#define ll long long
class Solution {
public:
  long long gridGame(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    ll ans = 1e10;
    vector<vector<ll>> prefix_sum(n, vector<ll>(m, 0));
    vector<vector<ll>> next_prefix_sum(n, vector<ll>(m, 0));
    for (int i = 0; i < m; i++){
      int ii = m - 1 - i;
      prefix_sum[0][i] += grid[0][i];
      prefix_sum[1][ii] += grid[1][ii];
      if (i > 0){
        prefix_sum[0][i] += prefix_sum[0][i - 1];
        prefix_sum[1][ii] += prefix_sum[1][ii + 1];
      }
    }
    
    for (int i = 0; i < m; i++){
      ll up_rest = prefix_sum[0].back() - prefix_sum[0][i];
      ll down_rest = prefix_sum[1][0] - prefix_sum[1][i];
      ll temp_blue_score = max(up_rest, down_rest);
      ans = min(ans, temp_blue_score);
    }
    return (ans);
  }
};