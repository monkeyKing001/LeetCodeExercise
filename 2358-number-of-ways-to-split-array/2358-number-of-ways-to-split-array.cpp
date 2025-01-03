#define ll long long
class Solution {
public:
  int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    vector<ll> left_dp(n, 0);
    vector<ll> right_dp(n, 0);
    ll temp = 0;
    for (int i = 0; i < n; i++){
      temp += (ll)nums[i];
      left_dp[i] += temp;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++){
      ll left_sum = left_dp[i] << 1;
      if (left_sum >= temp)
        ans++;
    }
    return (ans);
  }
};