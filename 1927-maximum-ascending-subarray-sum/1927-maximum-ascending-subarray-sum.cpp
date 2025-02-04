class Solution {
public:
  int maxAscendingSum(vector<int>& nums) {
    int n = nums.size();
    int l = 0;
    int ans = 0;
    while (l < n){
      int r = l + 1;
      int cur_num = nums[l];
      int temp_sum = nums[l];
      while (r < n && cur_num < nums[r]){
        temp_sum += nums[r];
        cur_num = nums[r];
        r++;
      }
      ans = max(ans, temp_sum);
      l = r;
    }
    return (ans);
  }
};