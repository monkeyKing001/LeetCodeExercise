class Solution {
public:
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> ans(prices.begin(), prices.end());
    vector<int> dp(prices.begin(), prices.end());
    for (int i = dp.size() - 1; i >= 0; i--){
      if (i != dp.size() - 1){
        dp[i] = min(dp[i], dp[i + 1]);
      }
    }
    for (int i = 0; i < ans.size(); i++){
      if (ans[i] >= dp[i]){
        int l = i + 1;
        while (l < ans.size()){
          if (ans[l] <= ans[i]){
            ans[i] -= ans[l];
            break;
          }
          l++;
        }
      }
    }
    return (ans);
  }
};