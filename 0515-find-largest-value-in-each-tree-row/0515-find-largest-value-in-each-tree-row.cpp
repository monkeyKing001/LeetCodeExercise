/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<unordered_set<int>> dp;
  void rec(TreeNode* node, int h){
    if (!node)
      return;
    dp[h].insert(node -> val);
    rec(node -> left, h + 1);
    rec(node -> right, h + 1);
  }

  vector<int> largestValues(TreeNode* root) {
    dp.resize(1000);
    rec(root, 0);
    vector<int> ans;
    for (int i = 0; i < dp.size(); i++){
      if (!dp[i].size())
        break;
      int max_val = INT_MIN;
      for (auto v : dp[i])
        max_val = max(max_val, v);
      ans.push_back(max_val);
    }
    return (ans);
  }
};