int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
using info = tuple<int, int, int>; //h, r, c
class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int n = isWater.size();
    int m = isWater[0].size();
    vector<vector<int>> ans (n, vector<int>(m, 0));
    vector<vector<int>> v (n, vector<int>(m, INT_MAX));
    priority_queue<info> pq;
    queue<info> q;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (isWater[i][j]){
          v[i][j] = 1;
          ans[i][j] = 0;
          q.push({0, i, j});
          pq.push({0, i, j});
        }
      }
    }
    while(q.size()){
      auto [min_adj_h, r, c] = q.front();
      q.pop();
      for (int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !isWater[nr][nc] && !ans[nr][nc]){
          ans[nr][nc] = min_adj_h + 1;
          q.push({min_adj_h + 1, nr, nc});
        }
      }
    }
    return (ans);
  }
};