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
  vector<TreeNode*> arr_tree;
  int node_num = 0;
  
  void mySwap(int l, int r){
    int temp = arr_tree[l] -> val;
    arr_tree[l] -> val = arr_tree[r] -> val;
    arr_tree[r] -> val = temp;
  }

  void rec(TreeNode *node, int idx){
    if (node == nullptr)
      return;
    arr_tree[idx] = node;
    node_num++;
    rec(node->left, (idx * 2) + 1);
    rec(node->right, (idx * 2) + 2);
  }

  TreeNode* reverseOddLevels(TreeNode* root) {
    unordered_map<int, int> height_info;
    arr_tree.resize(1'000'000, 0);
    for (int i = 0; i < 15; i++){
      node_num += pow(2, i);
      height_info[node_num] = i;
    }
    node_num = 0;
    rec(root, 0);
    int max_h = height_info[node_num];
    cout << "max_h : " << max_h;
    for (int i = 0 ; i <= max_h; i++){
      if (i % 2){
        int start = pow(2, i) - 1;
        int end = start * 2;;
        while (start < end){
          mySwap(start, end);
          start++;
          end--;
        }
      }
    }
    return (root);
  }
};