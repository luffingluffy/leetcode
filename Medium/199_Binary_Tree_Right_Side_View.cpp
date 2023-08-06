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
    vector<int> ans;

    void helper(int level, TreeNode* node) {
        if (level == ans.size()) {
            ans.push_back(node->val);
        }

        if (node->right != nullptr) {
            helper(level + 1, node->right);
        }

        if (node->left != nullptr) {
            helper(level + 1, node->left);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return ans;

        helper(0, root);
        return ans;
    }
};