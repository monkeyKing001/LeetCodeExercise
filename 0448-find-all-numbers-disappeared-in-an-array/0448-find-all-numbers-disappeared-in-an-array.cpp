class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    int count = n;
    for (int i = 0; i < n; i++){
      int num = abs(nums[i]);
      int idx = num - 1;
      if (nums[idx] > 0) nums[idx] = -nums[idx], count--;//if not visited checked yet, check
    }
    vector<int> ans(count, 0);
    int idx = 0;
    for (int i = 0; i < n; i++)
      if (nums[i] > 0) ans[idx++] = i + 1;
    return (ans);
  }
};