class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (auto &i : intervals){
      if (ans.size() && ans.back()[1] >= i[0]) ans.back()[1] = max(ans.back()[1], i[1]);
      else ans.push_back(i);
    }
    return (ans);
  }
};
// Error 1. applying non-zero offset 18446744073709551592 to null pointer (stl_iterator.h)