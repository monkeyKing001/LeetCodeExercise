class Solution {
public:
  unordered_set<int> term;
  set<int> safe;
  vector<bool> visited;
  void rec(int node, vector<vector<int>> &g){
    visited[node] = true;
    bool safe_node = true;
    for (auto next : g[node]){
      if (!visited[next])
        rec(next, g);
      if (!safe.contains(next)){
        safe_node = false;
        break;
      }
    }
    if (safe_node)
      safe.insert(node);
  }

  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    visited.resize(n , false);
    for (int i = 0 ; i < n; i++){
      if (!graph[i].size()){
        safe.insert(i);
        visited[i] = true;
      }
    }
    for (int i = 0; i < n; i++){
      if (!visited[i])
        rec(i, graph);
    }
    vector<int> ans(safe.begin(), safe.end());
    return (ans);
  }
};