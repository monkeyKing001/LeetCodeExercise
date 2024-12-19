class Solution {
public:
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> ans(prices.begin(), prices.end());
    stack<int> s;
    int n = prices.size();
    for (int i = n - 1; i >= 0; i--){
      while (!s.empty() && prices[s.top()] > prices[i])
        s.pop();
      if (s.size() != 0)
        ans[i] -= prices[s.top()];
      s.push(i);
    }
    return (ans);
  }
};