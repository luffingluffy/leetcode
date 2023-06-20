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
    // Iterative:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        int dist = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ans.push_back({});

            int num_nodes = q.size();
            for (int i = 0; i < num_nodes; i++) {
                TreeNode* curr = q.front();
                q.pop();

                ans[dist].push_back(curr->val);
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }

            dist++;
        }

        return ans;
    }

    // Recursive:
    // vector<vector<int>> ans;

    // void helper(TreeNode* node, int level) {
    //     if (ans.size() == level) {
    //         ans.push_back({});
    //     }

    //     ans[level].push_back(node->val);

    //     if (node->left != nullptr) helper(node->left, level + 1);
    //     if (node->right != nullptr) helper(node->right, level + 1);
    // }

    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     if (root == nullptr) return ans;

    //     helper(root, 0);
    //     return ans;
    // }
};