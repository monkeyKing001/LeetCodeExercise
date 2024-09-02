#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    int count = 0;
    vector<vector<int>> ret;
    if (m * n != original.size())
      return (ret);
    ret.resize(m);
    for (int i = 0; i < m; i++){
      ret[i].resize(n);
      for (int j = 0; j < n; j++){
        ret[i][j] = original[count++];
      }
    }
    return (ret);
  }
};