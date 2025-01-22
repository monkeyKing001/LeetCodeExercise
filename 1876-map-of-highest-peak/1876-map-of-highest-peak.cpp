int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
using info = pair<int, int>; //r, c
class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int n = isWater.size();
    int m = isWater[0].size();
    vector<vector<int>> ans (n, vector<int>(m, 0));
    queue<info> q;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (isWater[i][j]){
          ans[i][j] = 0;
          q.push({i, j});
        }
      }
    }
    while(q.size()){
      auto [r, c] = q.front();
      q.pop();
      for (int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !isWater[nr][nc] && !ans[nr][nc]){
          ans[nr][nc] = ans[r][c]+ 1;
          q.push({nr, nc});
        }
      }
    }
    return (ans);
  }
};