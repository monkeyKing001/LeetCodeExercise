class Solution {
public:
  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int n = words.size();
    vector<int> dp(n, 0);
    string vowels = "aeiou";
    for (int i = 0; i < n; i++){
      if (vowels.find(words[i][0]) != string::npos && vowels.find(words[i].back()) != string::npos)
        dp[i]++;
      if(i > 0)
        dp[i] += dp[i - 1];
    }
    vector<int> ans(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++){
      int l = queries[i][0];
      int r = queries[i][1];
      int temp = dp[r];
      if (l != 0)
        temp -= dp[l - 1];
      ans[i] = temp;
    }
    return (ans);
  }
};