using info = pair<int, int>;
class Solution {
public:
  int dr[4] = {-1, 1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  unordered_map<char, int> move_char = {{'N', 0}, {'S', 1}, {'E', 2}, {'W', 3}};
  unordered_map<int, int> count;
  int maxDistance(string s, int k) {
    int n = s.size();
    int ans = 0;
    int k_copy = k;
    vector<string> cases = {"NE", "NW", "SE", "SW"};
    for (int ci = 0; ci < cases.size(); ci++){
      count.clear();
      string temp = s;
      k = k_copy;
      for (auto &c : temp){
        if (!k)
          break;
        if (cases[ci].find(c) == string::npos){
          if (c == 'N') c = 'S';
          else if (c == 'S') c = 'N';
          else if (c == 'E') c = 'W';
          else if (c == 'W') c = 'E';
          k--;
        }
      }
      //cout << temp << "\n";
      for (auto chr : temp){
        int dir = move_char[chr];
        count[dir]++;
        ans = max(ans, abs(count[0] - count[1]) + abs(count[2] - count[3]));
      }
    }
    return (ans);
  }
};