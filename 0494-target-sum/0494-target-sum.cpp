class Solution {
public:
  int offset = 1000;
  int findTargetSumWays(vector<int>& nums, int target) {
    vector<vector<int>> dp(nums.size(), vector<int>(2200, 0));
    int num = nums[0];
    int n = nums.size();
    //if num = 1000 -> idx = 2000
    //if num = -1000 -> idx = 0
    dp[0][num + offset]++;
    dp[0][-num + offset]++;
    for (int i = 1; i < nums.size(); i++){
      int cur_num = nums[i];
      for (int j = 0; j < dp[i - 1].size(); j++){
        if (dp[i - 1][j]){
          dp[i][j + cur_num] += dp[i - 1][j];
          dp[i][j - cur_num] += dp[i - 1][j];
          //cout << "found prev history for " << j - offset << "\n";
          //cout << "index : " << j + cur_num << ", " << j - cur_num << "\n";
          //cout << "adding : " << j + cur_num - offset << ", " << j - cur_num - offset << "\n";
        }
      }
    }
    int ans = dp[n - 1][target + offset];
    return(ans);
  }
};