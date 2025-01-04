class Solution {
public:
  int bst(vector<vector<int>> &dp2, int check, int start, int end){
    int idx = -1;
    int l = 0, r = dp2[check].size() - 1;
    while (l <= r){
      int mid = (l + r) / 2;
      if (dp2[check][mid] < end && start < dp2[check][mid])
        return (mid);
      else if (dp2[check][mid] <= start)
        l = mid + 1;
      else if (dp2[check][mid] >= end)
        r = mid - 1;
    }
    return (idx);
  }
  int countPalindromicSubsequence(string s) {
    vector<vector<int>> dp(s.size(), vector<int> (26, 0));
    vector<vector<int>> dp2(26);
    for (int i = 0; i < s.size(); i++){
      int c_idx = s[i] - 'a';
      dp2[c_idx].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++){
      if (dp2[i].size() < 2)
        continue;
      int start = dp2[i].front();
      int end = dp2[i].back();
      for (int j = 0; j < 26; j++)
        if (dp2[j].size() != 0 && bst(dp2, j, start, end) != -1)
          ans++;
    }
    return (ans);
  }
};