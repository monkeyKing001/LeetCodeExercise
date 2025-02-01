class Solution {
public:
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int ans = 0;
    int n = startTime.size();
    int last_end = 0;
    vector<int> free_times(n + 1);
    vector<int> free_times_left_dp(n + 1, 0);
    vector<int> free_times_right_dp(n + 1, 0);
    vector<int> times(n);
    for (int i = 0; i < n; i++){
      int start = startTime[i];
      int time = endTime[i] - startTime[i];
      int free_time = start - last_end;
      free_times[i] = free_time;
      times[i] = time;
      last_end = endTime[i];
    }
    free_times[n] = eventTime - last_end;
    int fn = n + 1;
    for (int i = 1; i < fn; i++){
      free_times_left_dp[i] = max(free_times_left_dp[i - 1], free_times[i - 1]);
      free_times_right_dp[fn - 1 - i] = max(free_times_right_dp[fn - i], free_times[fn - i]);
    }
    //debeg print
    //for (auto f : free_times){
    //  cout << f << " ";
    //}
    //cout << "\n";
    //for (int i = 0; i < fn; i++)
    //  cout << free_times_left_dp[i] << " ";
    //cout << "\n";
    //for (int i = 0; i < fn; i++)
    //  cout << free_times_right_dp[i] << " ";
    //cout << "\n";
    for (int i = 0; i < fn; i++){
      int free_time = free_times[i];
      if (i != fn  - 1){
        int right_schedule = times[i];
        int next_free_time = free_times[i + 1];
        ans = max(ans, free_time + next_free_time);
        //if removable to right schedule
        if (free_times_right_dp[i + 1] >= right_schedule || free_times_left_dp[i] >= right_schedule)
          ans = max(ans, free_time + next_free_time + right_schedule);
      }
      if (i != 0){
        int left_schedule = times[i - 1];
        int prev_free_time = free_times[i - 1];
        ans = max(ans, free_time + prev_free_time);
        //if removable
        if (free_times_right_dp[i] >= left_schedule || free_times_left_dp[i - 1] >= left_schedule)
          ans = max(ans, free_time + prev_free_time + left_schedule);
      }
    }
    return (ans);
  }
};