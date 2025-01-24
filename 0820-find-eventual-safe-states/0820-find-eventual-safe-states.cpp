class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> rg(n);
    vector<int> indg(n, 0);
    for (int i = 0; i < n; i++){
      int u = i;
      for (auto v : graph[u]){
        rg[v].push_back(u);
        indg[u]++;
      }
    }
    vector<int> ans;
    ans.reserve(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!indg[i]) q.push(i);
    while (q.size()){
      int node = q.front();
      q.pop();
      ans.push_back(node);
      for (auto next : rg[node]){
        indg[next]--;
        if (!indg[next])
          q.push(next);
      }
    }
    sort(ans.begin(), ans.end());
    return(ans);
  }
};