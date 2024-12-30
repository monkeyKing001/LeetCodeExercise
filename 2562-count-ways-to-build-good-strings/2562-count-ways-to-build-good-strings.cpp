class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
      int MOD = 1000000007;
      int ans = 0;
      vector<vector<int>> dp(high + 2, vector<int> (2, 0));
      dp[zero][0] = 1;
      dp[one][1] = 1;
      for (int i = 0; i <= high; i++){
        //end with zero
        if (i - zero > 0){
          dp[i][0] += dp[i - zero][0];
          dp[i][0] %= MOD;
          dp[i][0] += dp[i - zero][1];
          dp[i][0] %= MOD;
        }
        //end with one
        if (i - one > 0){
          dp[i][1] += dp[i - one][0];
          dp[i][1] %= MOD;
          dp[i][1] += dp[i - one][1];
          dp[i][1] %= MOD;
        }
      }
      for (int i = low; i <= high; i++){
        ans += dp[i][0];
        ans %= MOD;
        ans += dp[i][1];
        ans %= MOD;
      }
      return (ans);
    }
};