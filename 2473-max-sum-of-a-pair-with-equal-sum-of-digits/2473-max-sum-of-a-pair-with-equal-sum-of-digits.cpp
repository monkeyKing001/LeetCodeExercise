class Solution {
public:
  int maximumSum(vector<int>& nums) {
    unordered_map<int, priority_queue<int>> info;
    for (auto nu : nums){
      int num = nu;
      int digit_sum = 0;
      while (nu){
        digit_sum += nu % 10;
        nu /= 10;
      }
      info[digit_sum].push(num);
    }
    int ans = -1;
    for (auto &[num, pq] : info){
      if (pq.size() >= 2){
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        ans = max(ans, n1 + n2);
      }
    }
    return (ans);
  }
};