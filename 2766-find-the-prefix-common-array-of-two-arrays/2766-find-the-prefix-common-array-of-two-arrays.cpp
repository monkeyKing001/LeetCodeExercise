class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> count(A.size() + 1, 0);
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++){
      int a_num = A[i];
      int b_num = B[i];
      if (a_num == b_num)
        dp[i]++;
      else{
        count[a_num]++, count[b_num]++;
        if (count[a_num] == 2) dp[i]++;
        if (count[b_num] == 2) dp[i]++;
      }
      if (i != 0)
        dp[i] += dp[i - 1];
    }
    return (dp);
  }
};