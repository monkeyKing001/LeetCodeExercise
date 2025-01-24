using info = pair<bool, int>; //row, node
class Solution {
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    int n = rowConditions.size();
    vector<vector<int>> mat(0);
    vector<int> row_indeg(k + 1, 0);
    vector<int> col_indeg(k + 1, 0);
    vector<vector<int>> rg(k + 1);
    vector<vector<int>> cg(k + 1);
    unordered_map<int, int> row_pos;
    unordered_map<int, int> col_pos;
    for (auto r : rowConditions){
      int u = r[0], v = r[1];
      rg[u].push_back(v);
      row_indeg[v]++;
    }
    for (auto c : colConditions){
      int u = c[0], v = c[1];
      cg[u].push_back(v);
      col_indeg[v]++;
    }
    queue<info> q;
    for (int i = 1; i < k + 1; i++){
      if (!row_indeg[i]) q.push({true, i});
      if (!col_indeg[i]) q.push({false, i});
    }
    while(q.size()){
      auto [is_row, node] = q.front();
      q.pop();
      unordered_map<int, int> &map_ = is_row ? row_pos : col_pos;
      vector<vector<int>> &g = is_row ? rg : cg; 
      vector<int> &indegree = is_row ? row_indeg : col_indeg; 
      map_.insert({node, map_.size()});
      for (int i = 0; i < g[node].size(); i++){
        int next = g[node][i];
        indegree[next]--;
        if (indegree[next] == 0) q.push({is_row, next});
      }
    }
    if (row_pos.size() != k || col_pos.size() != k) return(mat);
    mat.resize(k, vector<int>(k, 0));
    for (int i = 1; i <= k; i++){
      int ri = row_pos[i];
      int ci = col_pos[i];
      mat[ri][ci] = i;
    }
    return(mat);
  }
};