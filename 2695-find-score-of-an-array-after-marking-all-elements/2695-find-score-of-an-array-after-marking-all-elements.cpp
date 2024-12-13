#define ll long long
#define NUM first
#define IDX second
using info = pair<int, int>;
class Solution {
public:
  long long findScore(vector<int>& nums) {
    vector<info> infos(nums.size());
    set<int> chosen_idx;
    vector<bool> visited(nums.size());
    for (int i = 0; i < nums.size(); i++){
      infos[i].NUM = nums[i];
      infos[i].IDX = i;
    }
    ll ans = 0;
    sort(infos.begin(), infos.end());
    for (auto i : infos){
      auto [num, idx] = i;
      if (!visited[idx]){
        ans += num;
        if (idx - 1 >= 0)
          visited[idx - 1] = true;
        if (idx + 1 < nums.size())
          visited[idx + 1] = true;
      } 
      visited[idx] = true;
    }
    return (ans);
  }
};