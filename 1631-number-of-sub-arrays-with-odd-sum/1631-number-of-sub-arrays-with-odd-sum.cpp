#define ll long long
class Solution {
public:
  int numOfSubarrays(vector<int>& arr) {
    int n = arr.size();
    int mod = 1e9 + 7;
    vector<int> prefix_sum(n);
    vector<int> count(2, 0);
    partial_sum(arr.begin(), arr.end(), prefix_sum.begin());
    for (auto p: prefix_sum)
      count[p % 2]++;
    int ans = count[1];
    ans += (ll)((ll)count[1] * (ll)count[0]) % mod;
    return (ans);
  }
};