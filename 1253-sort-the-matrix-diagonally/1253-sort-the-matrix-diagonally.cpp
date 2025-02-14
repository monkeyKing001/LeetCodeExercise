class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int diag_num = n + m - 1;
    for (int i = 0; i < diag_num; i++){
      int start_r = i < n ? n - 1 - i : 0;
      int start_c = i < n ? 0 : i - n + 1; 
      priority_queue<int> pq;
      int cur_r = start_r, cur_c = start_c;
      while (cur_r < n && cur_c < m) pq.push(-mat[cur_r++][cur_c++]);
      cur_r = start_r, cur_c = start_c;
      while (cur_r < n && cur_c < m) {
        mat[cur_r++][cur_c++] = -pq.top();
        pq.pop();
      }
    }
    return (mat);
  }
};