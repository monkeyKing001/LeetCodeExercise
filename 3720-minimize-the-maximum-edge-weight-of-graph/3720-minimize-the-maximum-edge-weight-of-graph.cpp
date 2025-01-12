#define ll long long
using edge_info = tuple<int, int, int>;//w, from, to
using info = tuple<ll, ll, ll>; //w, cost, node
class Solution {
public:
  int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
    ll MAX_COST = 1e11;
    int max_w = 0;
    vector<ll> dp(n, MAX_COST);
    vector<int> indegree(n, 0);
    vector<unordered_map<int, int>> g(n);
    priority_queue<info, vector<info>, greater<info>> pq;
    for (auto e: edges){
      int r_from = e[1];
      int r_to = e[0];
      int cost = e[2];
      if (!g[r_from].count(r_to))
        g[r_from][r_to] = cost;
      else
        g[r_from][r_to] = min(g[r_from][r_to], cost);
    }
    pq.push({0, 0, 0});//w, node
    while (pq.size()){
      auto [w, cost, node] = pq.top();
      pq.pop();
      //visited already, continue
      if (dp[node] != MAX_COST)
        continue;
      //cout
      //  << "node, w, cost : "
      //  << node
      //  << ", "
      //  << w
      //  << ", "
      //  << cost
      //  << "\n";
      dp[node] = cost;
      max_w = max((int)w, max_w);
      for (auto e : g[node]){
        auto [next_node, next_w] = e;
        if (dp[next_node] == MAX_COST)//not visited, push pq
          pq.push({next_w, dp[node] + next_w, next_node});
      }
    }
    for (int i = 0; i < n && max_w != -1; i++){
      if (dp[i] == MAX_COST) max_w = -1;
    }
    return (max_w);
  }
};