using info = pair<int, int>;
class Solution {
public:

  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<info> srt(n);
    vector<int> group_info(n, -1);
    unordered_map<int, deque<int>> dsu;
    for (int i = 0; i < n; i++){
      int num = nums[i];
      srt[i].first = num;
      srt[i].second = i;
    }
    sort(srt.begin(), srt.end());
    int i = 0;
    while (i < n){
      int cur_num = srt[i].first;
      int p_idx = srt[i].second;
      int group_id = dsu.size();
      dsu[group_id].push_back(cur_num);
      group_info[p_idx] = group_id;
      int j = i + 1;
      while (j < n){
        int num = srt[j].first;
        int idx = srt[j].second;
        if (num - cur_num <= limit){
          group_info[idx] = group_id;
          dsu[group_id].push_back(num);
          //cout <<
          //"connected n1, n2 : "
          //  << cur_num
          //  << ", "
          //  << num
          //  << "\n";
          cur_num = num;
        }
        else break;
        j++;
      }
      i = j;
    }
    vector<int> ans;
    ans.reserve(n);
    i = 0;
    while (i < n){
      int j = i;
      while (j < n){
        if (group_info[i] == group_info[j]){
          ans.push_back(dsu[group_info[i]].front());
          dsu[group_info[i]].pop_front();
        }
        else break;
        j++;
      }
      i = j;
    }
    return (ans);
  }
};