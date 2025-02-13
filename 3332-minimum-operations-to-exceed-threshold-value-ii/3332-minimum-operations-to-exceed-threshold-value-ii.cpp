#define ll long long
class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    int ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());
    while (pq.size() >= 1){
      ll n1 = pq.top();
      pq.pop();
      if (n1 >= k)
        break;
      ll n2 = pq.top();
      pq.pop();
      ll next_num = min(n1, n2) * 2 + max(n1, n2);
      pq.push(next_num);
      ans++;
    }
    return (ans);
  }
};