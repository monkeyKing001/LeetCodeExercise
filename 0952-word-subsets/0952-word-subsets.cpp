class Solution {
public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string> ans;
    ans.reserve(words1.size());
    vector<int> w2_count(26, 0);
    for (auto &w2 : words2){
      vector<int> temp(26, 0);
      for (auto w2c : w2)
        temp[w2c - 'a']++;
      for (int i = 0; i < 26; i++)
        w2_count[i] = max(w2_count[i], temp[i]);
    }
    for (auto &w1 : words1){
      vector<int> ww1_count(26, 0);
      for (auto w1c : w1){
        ww1_count[w1c - 'a']++;
      }
      bool flag = true;
      for (int i = 0; i < 26 && flag; i++){
        if (w2_count[i] > ww1_count[i])
          flag = false;
      }
      if (flag) ans.push_back(w1);
    }
    return (ans);
  }
};