class Solution {
public:

  static bool cmp(string s1, string s2){
    if (s1.size() == s2.size())
      return (s1 < s2);
    return (s1.size() < s2.size());
  }

  vector<string> stringMatching(vector<string>& words) {
    vector<string> ans;
    int n = words.size();
    ans.reserve(n);
    sort(words.begin(), words.end(), cmp);
    for (int i = 0; i < n; i++){
      string &target = words[i];
      for (int j = i + 1; j < n; j++){
        string &hay = words[j]; 
        if (hay.find(target) != string::npos){
          ans.push_back(target);
          break;
        }
      }
    }
    return (ans);
  }
};