using info = pair<int, int>;
#define START first
#define END second
class Solution {
public:
  int maximumBeauty(vector<int>& nums, int k) {
    int sol = 0;
    sort(nums.begin(), nums.end());
    queue<info> pq;
    for (auto n : nums){
      int start = n - k;
      int end = n + k;
      info i = {start, end};
      while (pq.size() != 0 && pq.front().END < start)
        pq.pop();
      pq.push(move(i));
      sol = max(sol, (int)pq.size());
    }
    return (sol);
  }
};