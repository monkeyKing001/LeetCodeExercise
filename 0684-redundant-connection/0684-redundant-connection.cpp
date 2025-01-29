class Solution {
public:
  vector<int> p;

  int find_(int u){
    if (p[u] == -1)
      return (u);
    p[u] = find_(p[u]);
    return (p[u]);
  }

  void union_(int u, int v){
    int p_u = find_(u);
    int p_v = find_(v);
    if (p_v < p_u){
      int temp = p_u;
      p_u = p_v;
      p_v = temp;
    }
    p[p_v] = p_u;
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> ans;
    p.clear();
    p.resize(1001, -1);
    for (auto &e : edges){
      int u = e[0];
      int v = e[1];
      if (find_(u) == find_(v)){
        ans = e;
        break;
      }
      union_(u, v);
    }
    return (ans);
  }
};