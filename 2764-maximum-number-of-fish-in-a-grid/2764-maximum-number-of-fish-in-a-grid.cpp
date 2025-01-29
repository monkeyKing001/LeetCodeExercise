using pos = pair<int, int>;
class Solution {
public:
  int dr[4] = {0, 1, 0, -1};
  int dc[4] = {1, 0, -1, 0};
  int findMaxFish(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    queue<pos> q;
    vector<vector<bool>> v(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (!v[i][j] && grid[i][j]){
          int temp = 0;
          v[i][j] = true;
          q.push({i, j});
          while(q.size()){
            auto [r, c] = q.front();
            q.pop();
            temp += grid[r][c];
            for (int di = 0; di < 4; di++){
              int next_r = r + dr[di];
              int next_c = c + dc[di];
              if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m && !v[next_r][next_c] && grid[next_r][next_c]){
                q.push({next_r, next_c});
                v[next_r][next_c] = true;
              }
            }
          }
          ans = max(ans, temp);
        }
      }
    }
    return (ans);
  }
};