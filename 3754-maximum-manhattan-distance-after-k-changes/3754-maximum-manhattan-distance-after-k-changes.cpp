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
    for (auto &valid_dir : cases){
      count.clear();
      string temp = s;
      k = k_copy;
      for (auto &c : temp){
        if (k && valid_dir.find(c) == string::npos){
          if (c == 'N') c = 'S';
          else if (c == 'S') c = 'N';
          else if (c == 'E') c = 'W';
          else if (c == 'W') c = 'E';
          k--;
        }
        int dir = move_char[c];
        count[dir]++;
        ans = max(ans, abs(count[0] - count[1]) + abs(count[2] - count[3]));
      }
      //cout << temp << "\n";
    }
    return (ans);
  }
};