class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      map<char, int> index_map;
      vector<int> dp (s.size() +1, 0);
      int start = 0;
      int sol = 0;
      for (int i = 0; i < s.size(); i++){
        char cur_char = s[i];
        if (index_map.find(cur_char) == index_map.end()){
          if (i == 0)
            dp[i] = 1;
          else
            dp[i] = dp[i - 1] + 1;
        }
        else{
          int prev_index = index_map[cur_char];
          if (prev_index >= start){
            dp [i] = i - prev_index;
            start = prev_index + 1;
          }
          else if (prev_index < start){
            dp[i] = dp[i - 1] +1;
          }
        }
        index_map[cur_char] = i;
        sol = max(sol, dp[i]);
      }
      return (sol);
    }
};