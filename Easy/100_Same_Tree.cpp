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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Iterative:
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;

        // BFS, check every node
        queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);
        while (!queue.empty()) {
            TreeNode* p_tree = queue.front();
            queue.pop();
            TreeNode* q_tree = queue.front();
            queue.pop();

            // If p != q, return false
            if (p_tree->val != q_tree->val) {
                return false;
            }

            if (p_tree->left != NULL && q_tree->left != NULL) {
                queue.push(p_tree->left);
                queue.push(q_tree->left);
            } else if (p_tree->left != q_tree->left) {
                return false;
            }

            if (p_tree->right != NULL && q_tree->right != NULL) {
                queue.push(p_tree->right);
                queue.push(q_tree->right);
            } else if (p_tree->right != q_tree->right) {
                return false;
            }
        }

        return true;

        // Recursive:
        // if (p == NULL && q == NULL) return true;
        // if (p == NULL || q == NULL) return false;

        // if (p->val != q->val) return false;

        // return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};