class Solution {
public:
  vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    vector<int> ans(queries.size(), 0);
    unordered_map<int, int> nodes_of_color;
    unordered_map<int, int> color_of_node;
    int distinct = 0;
    for (int i = 0; i < queries.size(); i++){
      int idx = queries[i][0];
      int color = queries[i][1];
      //remove previous color
      if (color_of_node.contains(idx)){
        int prev_color = color_of_node[idx];
        nodes_of_color[prev_color]--;
        if (nodes_of_color[prev_color] == 0)
          distinct--;
      }
      //add node for color
      if (nodes_of_color[color] == 0)
        distinct++;
      nodes_of_color[color]++;
      color_of_node[idx] = color;
      ans[i] = distinct;
    }
    return (ans);
  }
};