class Solution {
public:
  bool check(vector<int>& nums) {
    int n = nums.size();
    int l = 0, count = 0, non_inc = 0;
    while (l < n && count != n){
      int next = (l + 1) % n;
      if (nums[l] > nums[next] && (non_inc++ != 0))
        return (false);
      count++;
      l++;
    }
    return (true);
      
  }
};