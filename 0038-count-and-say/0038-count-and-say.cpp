static vector<string> dp(31, "-1");
class Solution {
public:
    string countAndSay(int n) {
      if (n == 1){
        dp[1] = "1";
        return (dp[1]);
      }
      if (dp[n  - 1] == "-1")
        dp[n - 1] = countAndSay(n - 1);
      dp[n] = "";
      string prev = dp[n - 1];
      string new_str = "";
      int l = 0;
      while (l < prev.size()){
        char cur_chr = prev[l];
        int r = l;
        int count = 0;
        while (r < prev.size() && prev[r] == cur_chr)
         r++;
        count = r - l;
        l = r;
        string count_str = to_string(count);
        new_str = new_str + count_str;
        new_str.push_back(cur_chr);
      }
      dp[n] = new_str;
      return (dp[n]);
    }
};