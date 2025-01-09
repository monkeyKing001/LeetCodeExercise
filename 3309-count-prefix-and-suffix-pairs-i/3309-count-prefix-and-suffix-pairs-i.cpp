bool cmp(string s1, string s2){
  if (s1.size() == s2.size())
    return (s1 < s2);
  return (s1.size() < s2.size());
}
class Solution {
public:
  int countPrefixSuffixPairs(vector<string>& words) {
    int n = words.size();
    int ans = 0;
    //sort(words.begin(), words.end());
    for (int i = 0; i < n - 1; i++){
      string s1 = words[i];
      //cout << "s1 : " << s1 << "\n";
      for (int j = i + 1; j < n; j++){
        string s2 = words[j];
        //cout << s2 << "\n";
        //cout <<"rfind pos : "<< s2.rfind(s1) << "\n";
        //cout << "find last of : "<< s2.find_last_of(s1) << "\n";
        if (s2.find(s1) == (size_t)0 && s2.rfind(s1) == (size_t)(s2.size() - s1.size()))
          ans++;
      }
    }
    return (ans);
  }
};