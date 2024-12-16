using info = pair<int, int>;
class Solution {
public:
  vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    priority_queue <info, vector<info>, greater<info>> pq;
    for (int i = 0; i < nums.size(); i++) pq.push({nums[i], i});
    while (k-- > 0){
      auto [num, i] = pq.top();
      pq.pop();
      nums[i] = num * multiplier;
      pq.push({nums[i], i});
    }
    return nums;
  }
};