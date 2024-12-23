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
using info = pair<TreeNode*, int>;
class Solution {
public:
    int minimumOperations(TreeNode* root) {
      queue<info> q;
      int cur_h = 0;
      int sol = 0;
      q.push({root, cur_h});
      while (q.size() != 0){
        vector<int> arr;
        while (q.size() != 0 && q.front().second == cur_h){
          auto[node, h] = q.front(); 
          arr.push_back(node -> val);
          q.pop();
          if (node -> left)
            q.push({node->left, cur_h + 1});
          if (node -> right)
            q.push({node->right, cur_h + 1});
        }
        vector<int> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < sorted.size(); i++){
          if (arr[i] != sorted[i]){
            for (int j = i + 1; j < arr.size() && arr[i] != sorted[i]; j++){
              if (arr[j] == sorted[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
              }
            }
            sol++;
          }
        }
        cout << "\n";
        cur_h++;
      }
      return (sol);
    }
};