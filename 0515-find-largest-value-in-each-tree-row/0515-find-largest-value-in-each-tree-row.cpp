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
  vector<int> dp;
  vector<bool> visit;
  void rec(TreeNode* node, int h){
    if (!node)
      return;
    if (dp.size() == h)
      dp.push_back(node -> val);
    dp[h] = max(dp[h], node -> val);
    rec(node -> left, h + 1);
    rec(node -> right, h + 1);
  }

  vector<int> largestValues(TreeNode* root) {
    vector<int> ans;
    rec(root, 0);
    for (int i = 0; i < dp.size(); i++) ans.push_back(dp[i]);
    return (ans);
  }
};