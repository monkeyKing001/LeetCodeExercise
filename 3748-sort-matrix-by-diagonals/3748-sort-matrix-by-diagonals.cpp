class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    //left bottom sort
    int n = grid.size();
    vector<vector<int>> sol(n, vector<int>(n, 0));
    priority_queue<int> pq;
    for (int i = 0; i < n; i++){
      int start_r = i, start_c = 0;
      int cur_r = start_r, cur_c = start_c;
      while (cur_r < n && cur_c < n) pq.push(grid[cur_r++][cur_c++]);
      cur_r = start_r, cur_c = start_c;
      while (cur_r < n && cur_c < n){
        sol[cur_r++][cur_c++] = pq.top();
        pq.pop();
      }
    }
    //right top sort
    for (int i = 1; i < n; i++){
      int start_r = 0, start_c = i;
      int cur_r = start_r, cur_c = start_c;
      while (cur_r < n && cur_c < n) pq.push(-grid[cur_r++][cur_c++]);
      cur_r = start_r, cur_c = start_c;
      while (cur_r < n && cur_c < n){
        sol[cur_r++][cur_c++] = -pq.top();
        pq.pop();
      }
    }
    return (sol);
  }
};