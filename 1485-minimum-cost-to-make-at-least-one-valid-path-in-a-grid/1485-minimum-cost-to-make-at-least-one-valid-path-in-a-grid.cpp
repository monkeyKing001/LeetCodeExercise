using move_info = tuple<int, int, int>;//r, c, direction;
using info = pair<int, move_info>;//change_chance_count, move_info
class Solution {
public:
  int dr[5] =  {0, 0, 0, 1, -1};
  int dc[5] =  {0, 1, -1, 0, 0};
  int minCost(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> v(m, vector<bool>(n, false));
    priority_queue<info, vector<info>, greater<info>> pq;
    pq.push({0, {0, 0, 0}});
    int ans = 0;
    while (pq.size()){
      auto [chance_count, cur_move_info] = pq.top();
      auto [cur_r, cur_c, cur_comming_d] = cur_move_info;
      pq.pop();
      if (v[cur_r][cur_c])
        continue;
      v[cur_r][cur_c] = true;
      int next_d = grid[cur_r][cur_c];
      if (cur_r == m - 1 && cur_c == n - 1 && (ans = chance_count)) break;
      for (int d_i = 1; d_i <= 4; d_i++){
        int next_r = cur_r + dr[d_i];
        int next_c = cur_c + dc[d_i];
        if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n && !v[next_r][next_c])
          pq.push({chance_count + (next_d != d_i),{next_r, next_c, d_i}});
      }
    }
    return (ans);
  }
};