class Solution {
public:
  int prev_days_d[3] = {1, 7, 30};

  int bst(vector<int> &days, int today, int prev_days){
    int idx = -1;
    int prev = today - prev_days;
    int l = 0, r = days.size() - 1; 
    while (l <= r){
      int mid = (l + r) / 2;
      if (days[mid] <= prev){
        idx = mid;
        l = mid + 1;
      }
      else 
        r = mid - 1;
    }
    return (idx);
  }

  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int max_cost = 36500000;
    vector<int> dp(days.size(), max_cost);
    int ans = 0;
    for (int i = 0; i < days.size(); i++){
      int cur_day = days[i];
      for (int j = 0; j < 3; j++){
        int prv_day = prev_days_d[j];
        int idx = bst(days, cur_day, prv_day);
        if (idx != -1)
          dp[i] = min(dp[i], dp[idx] + costs[j]);
        else
          dp[i] = min(dp[i], costs[j]);
      }
    }
    return dp.back();
  }
};