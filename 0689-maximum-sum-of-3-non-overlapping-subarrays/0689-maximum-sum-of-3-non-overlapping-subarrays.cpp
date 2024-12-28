#define SUM first
#define IDX second
using info = pair<int, int>;
class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> sum(n, 0);
    vector<info> left_dp(n);
    vector<info> right_dp(n);
    int temp_sum = 0;
    for (int i = 0; i < nums.size(); i++){
      temp_sum += nums[i];
      if (i >= k - 1){
        sum[i] = temp_sum;
        temp_sum -= nums[i - (k - 1)];
      }
    }
    for (int i = k - 1; i < sum.size(); i++){
      if (i != 0)
        left_dp[i] = left_dp[i - 1];
      else left_dp[i].SUM = sum[i], left_dp[i].IDX = i;
      //left_dp[i].SUM = left_dp[i - 1].SUM;
      //left_dp[i].IDX = left_dp[i - 1].IDX;
      if (sum[i] > left_dp[i].SUM){
        left_dp[i].SUM = sum[i];
        left_dp[i].IDX = i;
      }
    }
    right_dp.back().SUM = sum.back();
    right_dp.back().IDX = n - 1;
    for (int i = n - 2; i >= k - 1; i--){
      right_dp[i] = right_dp[i + 1];
      if (sum[i] >= right_dp[i].SUM){
        right_dp[i].SUM = sum[i];
        right_dp[i].IDX = i;
      }
    }
    int temp = INT_MIN;
    vector<int> ans(3, 0);
    for (int i = (2 * k) - 1; i < n - 1 - (k - 1); i++){
      int left_idx = i - k;
      int right_idx = i + k;
      if (sum[i] + left_dp[left_idx].SUM + right_dp[right_idx].SUM > temp){
        temp = sum[i] + left_dp[left_idx].SUM + right_dp[right_idx].SUM;
        int left_start = left_dp[left_idx].IDX - (k - 1);
        int mid_start = i - (k - 1);
        int right_start = right_dp[right_idx].IDX - (k - 1);
        //cout << "l, m, r : "
        //<< left_start
        //<< ", "
        //<< mid_start
        //<< ", "
        //<< right_start
        //<< "\n";
        ans = {left_start, mid_start, right_start};
      }
    }
    return (ans);
  }
};