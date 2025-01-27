using info = pair<int, int>;
class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    int n = numCourses;
    int qn = queries.size();
    vector<bool> ans(qn, false);
    vector<vector<int>> g(n);
    vector<unordered_set<int>> dep(n);
    vector<int> indegree(n, 0);
    for (auto p : prerequisites){
      int u = p[0];
      int v = p[1];
      g[u].push_back(v);
      dep[v].insert(u);
      indegree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (!indegree[i]) q.push(i);
    while (q.size()){
      int node = q.front();
      q.pop();
      for (auto next : g[node]){
        indegree[next]--;
        dep[next].insert(node);
        for (auto dn : dep[node]) dep[next].insert(dn);
        if (!indegree[next]) q.push(next);
      }
    }
    for (int qi = 0; qi < qn; qi++){
      int u = queries[qi][0], v = queries[qi][1];
      ans[qi] = dep[v].contains(u);
    }
    return (ans);
;  }
};