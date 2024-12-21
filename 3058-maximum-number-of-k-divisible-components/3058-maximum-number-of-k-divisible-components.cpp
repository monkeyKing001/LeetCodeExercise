class Solution {
public:

  long long rec(int prev, int node, vector<vector<int>>& g, vector<long long> &dp, vector<int> &values) {
    if (dp[node] != -1)
      return (dp[node]);
    dp[node] = values[node];
    for (auto children : g[node]){
      if (children == prev)
        continue;
      dp[node] += rec(node, children, g, dp, values);
    }
    return dp[node];
  }
  
  int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    vector<long long> dp(n, -1);
    vector<vector<int>> g(n);
    for (auto e : edges){
      int u = e[0];
      int v = e[1];
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int ans = 0;
    rec(-1, 0, g, dp, values);
    for (auto s : dp){
      if (s % k == 0)
        ans++;
      //cout << s << " ";
    }
    return (ans);
  }
};