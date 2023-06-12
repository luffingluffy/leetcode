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
    TreeNode* invertTree(TreeNode* root) {
        // iterative:
        if (root == nullptr) {
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.top();
            q.pop();

            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }

        return root;

        // recursive:
        // if (root == nullptr) {
        //     return nullptr;
        // } else {
        //     TreeNode* temp = root->left;
        //     root->left = invertTree(root->right);
        //     root->right = invertTree(temp);
        // }

        // return root;
    }
};