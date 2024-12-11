
class Solution {
public:
  unordered_map<int, int> indegree;
  unordered_map<int, int> outdegree;
  unordered_map<int, stack<int>> g;
  
  void Euler(int cur, vector<pair<int, int>> &path){
    //cout << "cur : " << cur << "\n";
    stack<int> &children = g[cur];
    while (children.size() != 0){
      int next = children.top();
      children.pop();
      Euler(next, path);
      path.push_back({cur, next});
    }
  }

  vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    //make graph
    for (auto v : pairs){
      int from = v[0];
      int to = v[1];
      indegree[to]++;
      outdegree[from]++;
      g[from].push(to);
    }
    int start = pairs[0][0];
    //find start point
    for (auto info : g){
      int node = info.first;
      if (indegree[node] < outdegree[node])
        start = node;
    }
    vector<vector<int>> ans;
    ans.reserve(pairs.size());
    vector<pair<int, int>> path;
    Euler(start, path);
    while (path.size() != 0){
      auto [from, to] = path.back();
      path.pop_back();
      ans.push_back({from, to});
    }
    return (ans);
  }
};