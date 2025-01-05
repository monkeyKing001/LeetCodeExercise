#define ll long long
class Solution {
public:
  long long calculateScore(string s) {
    ll score = 0;
    vector<vector<int>> idxes(26);
    for (int i = 0; i < s.size(); i++){
      int idx = s[i] - 'a';
      int mirr_idx = 25 - idx;
      idxes[idx].push_back(i);
      if (idxes[mirr_idx].size()){
        score += i - idxes[mirr_idx].back(); 
        idxes[mirr_idx].pop_back();
        idxes[idx].pop_back();
      }
    }
    return(score);
      
  }
};