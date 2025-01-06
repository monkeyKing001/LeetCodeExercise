class Solution {
public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> ans(n, 0);
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    vector<int> left_count(n, 0);
    vector<int> right_count(n, 0);
    for (int i = n - 1; i >= 0; i--){
      if (boxes[i] == '1')
        right_count[i]++;
      if (i < n - 1)
        right_count[i] += right_count[i + 1];
      if (i < n - 1 && right_count[i + 1]) right[i] = right[i + 1] + right_count[i + 1];
    }
    for (int i = 0; i < n; i++){
      if (boxes[i] == '1')
        left_count[i]++;
      if (i > 0)
        left_count[i] += left_count[i - 1];
      if (i > 0 && left_count[i - 1]) left[i] = left[i - 1] + left_count[i - 1];
    }
    for (int i = 0; i < n; i++){
      ans[i] = left[i] + right[i];
    }
    return (ans);
  }
};