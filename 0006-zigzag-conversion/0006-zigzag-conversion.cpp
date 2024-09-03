class Solution {
public:
    int dr[2] = {1, -1};
    int dc[2] = {0, 1};
    string convert(string s, int numRows) {
      int cur_dir = 0;
      vector<vector<char>> matrix(numRows, vector<char>(s.size(), 0));
      int r = 0, c = 0;
      for (int i = 0; i < s.size(); i++){
        char chr = s[i];
        matrix[r][c] = chr;
        if (r == numRows - 1)
          cur_dir = 1;
        else if (r == 0)
          cur_dir = 0;
        r += dr[cur_dir];
        c += dc[cur_dir];
        if (r == -1)
          r = 0;
      }
      string sol = "";
      for (int i = 0; i < numRows; i++){
        for (int j = 0; j < s.size(); j++){
          if (matrix[i][j] != 0)
            sol.push_back(matrix[i][j]);
        }
      }
      return sol;
    }
};