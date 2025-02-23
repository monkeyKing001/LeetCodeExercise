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
  void rec(vector<int> &pre, vector<int> &post, int pre_l, int pre_r, int post_l, int post_r, TreeNode *parent){
    //set parent
    //parent -> value = post[r];
    parent -> val = pre[pre_l];
    if (pre_l == pre_r)
      return;
    int left_val = pre[pre_l + 1];
    int right_val = post[post_r - 1];
    //make left_tree
    int next_pre_l = pre_l + 1;
    int next_pre_r = next_pre_l;
    while (next_pre_r + 1 <= pre_r && pre[next_pre_r + 1] != right_val) next_pre_r++;
    int next_post_l = post_l;
    int next_post_r = post_l;
    while (next_post_r <= post_r && post[next_post_r] != left_val) next_post_r++;
    if (next_post_l <= next_post_r && next_pre_l <= next_pre_r){
      parent -> left = new TreeNode();
      rec(pre, post, next_pre_l, next_pre_r, next_post_l, next_post_r, parent -> left);
    }
    //make right_tree
    next_post_l = next_post_r + 1;
    next_post_r = post_r - 1;
    next_pre_l = next_pre_r + 1;
    next_pre_r = pre_r;
    if (left_val != right_val && next_post_l <= next_post_r && next_pre_l <= next_pre_r){
      parent -> right = new TreeNode();
      rec(pre, post, next_pre_l, next_pre_r, next_post_l, next_post_r, parent -> right);
    }
  }

  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int n = pre.size();
    TreeNode *root = new TreeNode();
    rec(pre, post, 0, n - 1, 0, n - 1, root);
    return (root);
  }
};