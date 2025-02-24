using amount_info = pair<int, int>;//price, step_time
using move_info = tuple<int, int, int>; //cur_node, cur_step, score_sum;
#define PRICE_OR_COST first
#define STEP_TIME second
const int max_step_time = 1e7 + 7;

class Solution {
public:
  bool rec_bob_travel(int prev_node, int cur_node, int cur_step, vector<vector<int>> &g, vector<amount_info> &amount_){
    if (cur_node == 0) amount_[cur_node].STEP_TIME = cur_step;
    for (int i = 0; i < g[cur_node].size(); i++){
      int next_node = g[cur_node][i];
      if (next_node != prev_node && \
        rec_bob_travel(cur_node, next_node, cur_step + 1, g, amount_))
          amount_[cur_node].STEP_TIME = cur_step;
    }
    return(amount_[cur_node].STEP_TIME != max_step_time);
  }

  int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int ans = INT_MIN;
    int n = edges.size() + 1;
    vector<vector<int>> g(n);
    vector<amount_info> amount_(n);
    for (auto &e: edges){
      int u = e[0], v = e[1];
      g[u].push_back(v), g[v].push_back(u);
    }
    //make bob travel
    for (int i = 0; i < n; i++) amount_[i] = {amount[i], max_step_time};
    rec_bob_travel(-1, bob, 0, g, amount_);
    queue<move_info> q;
    vector<bool> v(n, false);
    v[0] = true;
    q.push({0, 0, amount_[0].PRICE_OR_COST});//cur_node, cur_step, price_or_cost_sum
    while (q.size()){
      auto[node, cur_step, p_or_c_sum] = q.front();
      q.pop();
      bool is_leaf = true;
      for (int i = 0; i < g[node].size(); i++){
        int next = g[node][i];
        int next_step = cur_step + 1;
        if (!v[next]){
          v[next] = true;
          is_leaf = false;
          int next_p_or_c = amount_[next].PRICE_OR_COST;
          //bob has visited already
          if (amount_[next].STEP_TIME < next_step) next_p_or_c = 0;
          //visit simutaneously
          else if(amount_[next].STEP_TIME == next_step) next_p_or_c /= 2;
          q.push({next, next_step, p_or_c_sum + next_p_or_c});
        }
      }
      if (is_leaf) ans = max(ans, p_or_c_sum); 
    }
    return (ans);
  }
};