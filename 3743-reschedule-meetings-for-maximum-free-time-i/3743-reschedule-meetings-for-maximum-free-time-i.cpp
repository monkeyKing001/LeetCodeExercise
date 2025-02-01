class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    int last_end = 0;
    vector<int> free_times(n + 1);
    for (int i = 0; i < n; i++){
      int start = startTime[i];
      int free_time = start - last_end;
      free_times[i] = free_time;
      last_end = endTime[i];
    }
    free_times[n] = eventTime - last_end;
    int fn = free_times.size();
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < fn; i++){
      sum += free_times[i];
      ans = max(ans, sum);
      if (i >= k){
        sum -= free_times[i - k];
      }
    }
    return (ans);
  }
};