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
class FindElements {
public:
    vector<int> arr;

    void fill_tree(int idx, TreeNode* node){
      if (idx >= arr.size())
        return ;
      arr[idx] = idx;
      //cout << "idx : " << idx << "\n";
      if (node -> left) fill_tree((idx * 2) + 1, node -> left);
      if (node -> right) fill_tree((idx * 2) + 2, node -> right);
    }
    
    FindElements(TreeNode* root) {
      arr.resize(1e6 + 1, -1);
      fill_tree(0, root);
    }

    bool find(int target) {
      return (arr[target] != -1);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */