class Solution {
public:
  int tupleSameProduct(vector<int>& nums) {
    unordered_map<int, int> count;
    int n = nums.size();
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
      for (int j = i + 1; j < n; j++){
        count[nums[i] * nums[j]]++;
      }
    }
    for (auto &[mul, c] : count){
      if (c != 1)
        ans += 4 * c * (c - 1);
    }
    return (ans);
  }
};