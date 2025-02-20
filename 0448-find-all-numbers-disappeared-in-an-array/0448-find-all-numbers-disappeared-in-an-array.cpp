class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    int iterating = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++){
      int ball = nums[i];
      int expected = i + 1;
      iterating++;
      if (ball != expected){
        nums[i] = -1;
        int pass_idx = ball - 1;
        while(pass_idx >= 0 && nums[pass_idx] != ball){
          int temp = nums[pass_idx];
          nums[pass_idx] = ball;
          ball = temp;
          pass_idx = temp - 1;
          iterating++;
        }
      }
    }
    for (int i = 0; i < n; i++)
      if (nums[i] == -1) ans.push_back(i + 1);
    return (ans);
  }
};