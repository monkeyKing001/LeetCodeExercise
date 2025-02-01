class Solution {
public:
  bool isArraySpecial(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0 ; i + 1 < n ; i++){
      if (!((nums[i] + nums[i + 1]) % 2))
        return (false);
    }
    return (true);
  }
};