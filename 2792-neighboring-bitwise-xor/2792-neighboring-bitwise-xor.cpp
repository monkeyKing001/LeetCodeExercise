class Solution {
public:
  bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();
    bool start = true;
    bool cur = start;
    for (int i = 0; i < n - 1; i++){
      if (derived[i])
        cur = (cur == 0);
    }
    if (cur == start && derived.back() == 1)
      return false;
    if (cur != start && derived.back() == 0)
      return false;
    return (true);
  }
};