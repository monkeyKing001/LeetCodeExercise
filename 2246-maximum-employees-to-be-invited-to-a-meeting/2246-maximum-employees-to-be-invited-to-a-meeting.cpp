using info = tuple<int, int, int>;//root, cur_node, prev
class Solution {
public:
  int non_cycle_node_count = 0;
  int biggest_cycle_node_count = 0;
  int ans = 0;
  bool rec(int root, int node, vector<vector<int>> &rev_g, vector<bool> &v, vector<bool> &is_cycle, int &depth){
    v[node] = true;
    if (!rev_g[node].size())
      return(false);
    //cout << "detecting cycle!, node : " << node << "\n";
    for (auto next : rev_g[node]){
      if (next == root){
        is_cycle[node] = true;
        //cout << "detecting end. root : " << root << "\n";
        break;
      }
      if (v[next]){
        if (is_cycle[next]){
          is_cycle[node] = is_cycle[next];
          break;
        }
      }
      else if(rec(root, next, rev_g, v, is_cycle, depth)){
        is_cycle[node] = true;
        depth += 1;
        break;
      }
    }
    return (is_cycle[node]);
  }

  int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size();
    vector<int> indegree(n, 0);
    vector<int> depth_from_root(n, 0);
    vector<int> longest_depth_to_leaf(n, 0);
    vector<bool> v(n, 0);
    vector<bool> is_cycle(n, false);
    vector<vector<int>> rev_g(n);
    unordered_set<int> safe;
    for (int i = 0; i < n; i++){
      int to = favorite[i];
      if (favorite[to] == i){
        safe.insert(i);
        continue;
      }
      indegree[i]++;
      rev_g[to].push_back(i);
    }
    //travel non cycle tree path
    queue<info> q;
    for (int i = 0; i < indegree.size(); i++){
      if (!indegree[i]) q.push({i, i, i});
    }
    while (q.size()){
      auto [root, node, prev] = q.front();
      q.pop();
      v[node] = true;
      depth_from_root[node] = depth_from_root[prev] + 1;
      if (!rev_g[node].size())
        longest_depth_to_leaf[root] = max(longest_depth_to_leaf[root], depth_from_root[node]);
      for (auto next : rev_g[node])
        if (!(--indegree[next])) q.push({root, next, node});
    }
    for (auto safe_node : safe)
      non_cycle_node_count += longest_depth_to_leaf[safe_node];

    //travel cycle graph
    for (int i = 0; i < v.size(); i++){
      if (!v[i]){
        int temp_depth = 1;
        if (rec(i, i, rev_g, v, is_cycle, temp_depth)){
          biggest_cycle_node_count = max(biggest_cycle_node_count, temp_depth);
          //cout << "cycle size : " << temp_depth << "\n";
        }

      }
    }
    ans = max(non_cycle_node_count, biggest_cycle_node_count);
    return (ans);
  }
};