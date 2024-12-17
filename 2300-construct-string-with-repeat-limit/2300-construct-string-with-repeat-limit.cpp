using info = pair<char, int>;
class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
    vector<int> count(26, 0);
    for (auto c : s)
      count[c - 'a']++;
    priority_queue<info> pq;
    for (int i = 0; i < count.size(); i++){
      if (count[i])
        pq.push({i + 'a' , count[i]});
    }
    string buffer;
    buffer.reserve(s.size());
    while (pq.size() != 0){
      auto [c, count_c] = pq.top();
      pq.pop();
      string temp_buf(min(count_c, repeatLimit), c);
      if (count_c > repeatLimit && pq.size() != 0){
        auto [next_c, next_count_c] = pq.top();
        pq.pop();
        temp_buf.push_back(next_c);
        if (--next_count_c > 0){
          pq.push({next_c, next_count_c});
        }
        count_c -= repeatLimit;
        pq.push({c, count_c});
      }
      buffer += temp_buf;
    }
    return (buffer);
  }
};