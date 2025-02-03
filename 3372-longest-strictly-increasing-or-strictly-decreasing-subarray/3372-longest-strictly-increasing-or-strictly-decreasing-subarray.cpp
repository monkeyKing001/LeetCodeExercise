class Solution {
public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int n = nums.size();
    int ans = 1;
    int l = 0;
    while (l < n - 1){
      int r = l + 1;
      if (nums[l] == nums[r]){
        l = r;
        continue;
      }
      bool inc = nums[l] < nums[r];
      while (r + 1 < n && (nums[r] != nums[r + 1]) && (nums[r] < nums[r + 1] == inc)) r++;
      int len = r - l + 1;
      ans = max(ans, len);
      l = r;
    }
    return (ans);
  }
};