class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++){
      int num = abs(nums[i]);
      int idx = num - 1;
      if (nums[idx] > 0) nums[idx] = -nums[idx];//if not visited checked yet, check
    }
    for (int i = 0; i < n; i++)
      if (nums[i] > 0) ans.push_back(i + 1);
    return (ans);
  }
};