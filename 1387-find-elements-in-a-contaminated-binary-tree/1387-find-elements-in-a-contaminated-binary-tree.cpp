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
    unordered_set<int> elemnts;

    void fill_tree(int idx, TreeNode* node){
      if (idx >= 1000001)
        return ;
      elemnts.insert(idx);
      if (node -> left) fill_tree((idx * 2) + 1, node -> left);
      if (node -> right) fill_tree((idx * 2) + 2, node -> right);
    }
    
    FindElements(TreeNode* root) {
      fill_tree(0, root);
    }

    bool find(int target) {
      return (elemnts.contains(target));
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */