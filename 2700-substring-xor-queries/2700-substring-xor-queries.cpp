using pos = pair<int, int>;
class Solution {
public:
  vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
    unordered_map<int, pos> map;
    vector<vector<int>> ans;
    int n = s.size(), q = queries.size();
    for (int i = 0; i < s.size(); i++){
      if (s[i] == '0'){
        if (!map.count(0)) map[0] = {i, i};
        continue;
      }
      int num = 0;
      for (int j = i; j <= min(i + 31, n - 1); j++){
        num = (num << 1) + (s[j] - '0');
        if (!map.count(num)) map[num] = {i, j};                
      }
    }
    for(int i = 0; i < q; i++){
      int num = queries[i][0] ^ queries[i][1];
      if (map.count(num)) ans.push_back({map[num].first, map[num].second});
      else  ans.push_back({-1,-1});
    }
    return (ans);
  }
};