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
    bool isSame(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr || t2 == nullptr) {
            return t1 == nullptr && t2 == nullptr;
        }

        return t1->val == t2->val && isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
    };

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        if (root == nullptr) return false;

        return isSame(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};