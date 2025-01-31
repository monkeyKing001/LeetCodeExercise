using info = pair<int, int>;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, -1, 0, 1};
class Solution {
public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int ans = 1;
    unordered_map<int, int> area_size_info;
    vector<vector<int>> area(n, vector<int> (n, -1));
    vector<vector<bool>> v(n, vector<bool> (n, false));
    queue<info> q;
    area_size_info[-1] = 0;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (!v[i][j] && grid[i][j]){
          int area_num = area_size_info.size();
          int area_size = 0;
          v[i][j] = true;
          q.push({i, j});
          while (q.size()){
            area_size++;
            auto [r, c] = q.front();
            q.pop();
            area[r][c] = area_num;
            area_size_info[area_num]++;
            for (int di = 0 ; di < 4; di++){
              int next_r = r + dr[di], next_c = c + dc[di];
              if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n && grid[next_r][next_c] && !v[next_r][next_c]){
                q.push({next_r, next_c});
                v[next_r][next_c] = true;
              }
            }
          }
          ans = max(area_size_info[area_num], ans);
        }
      }
    }
    //try connection;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (!v[i][j] && !grid[i][j]){
          unordered_set<int> areas;
          int temp_size = 1;
          for (int di = 0 ; di < 4; di++){
            int next_r = i + dr[di], next_c = j + dc[di];
            if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n) areas.insert(area[next_r][next_c]);
          }
          for (auto area : areas)
            temp_size += area_size_info[area];
          ans = max(temp_size, ans);
        }
      }
    }
    return (ans);
  }
};