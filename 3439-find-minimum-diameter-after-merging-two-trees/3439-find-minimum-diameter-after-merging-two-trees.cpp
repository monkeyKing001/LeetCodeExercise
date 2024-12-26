using info = tuple<int, int, int>; 
class Solution {
public:
  int findStart(vector<vector<int>> &g){
    queue<info> q;
    int g_start = -1;
    q.push({0, -1, 0});
    while (q.size()){
      auto[cur, prev, len] = q.front();
      q.pop();
      for (auto c : g[cur]){
        if (prev != c)
          q.push({c, cur, len + 1});
      }
      if (q.empty())
        g_start = cur;
    }
    return (g_start);
  }

  int findDiameter(vector<vector<int>> &g, int start){
    queue<info> q;
    int g_start = start;
    int diameter = 0;
    q.push({g_start, -1, diameter});
    while (q.size()){
      auto[cur, prev, len] = q.front();
      q.pop();
      for (auto c : g[cur]){
        if (prev != c)
          q.push({c, cur, len + 1});
      }
      if (q.empty())
        diameter = len;
    }
    return (diameter);
  }

  int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    vector<vector<int>> g1(edges1.size() + 1);
    vector<vector<int>> g2(edges2.size() + 1);
    int g1_len = 0;
    int g2_len = 0;
    for (auto e1: edges1){
      int u = e1[0];
      int v = e1[1];
      g1[u].push_back(v);
      g1[v].push_back(u);
    }
    for (auto e2: edges2){
      int u = e2[0];
      int v = e2[1];
      g2[u].push_back(v);
      g2[v].push_back(u);
    }
    int g1_start = findStart(g1);
    int g2_start = findStart(g2);
    int g1_diameter = findDiameter(g1, g1_start);
    int g2_diameter = findDiameter(g2, g2_start);
    cout << "g1, g2_diameter : " << g1_diameter << ", " << g2_diameter;
    int ans = (g1_diameter / 2) + \
            (g2_diameter / 2) + \
            (g1_diameter % 2) + \
            (g2_diameter % 2) + \
            + 1;
    ans = max(ans, g1_diameter);
    ans = max(ans, g2_diameter);
    return (ans);
  }
};