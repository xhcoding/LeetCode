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
    
    // 自顶向下，遍历求解
    int maxDepth(TreeNode* root) {
        int res = 0;    // 最大深度
        int depth = 0;  // 当前节点深度
        traverse(root, res, depth);
        return res;
    }

    void traverse(TreeNode* root, int& res, int& depth) {
        if (!root) {
            return;
        }
        depth++;
        if (root->left == nullptr || root->right == nullptr) {
            // 当前节点是叶子节点，更新最大深度
            res = max(res, depth);
        }
        traverse(root->left, res, depth);
        traverse(root->right, res, depth);
        depth--;
    }

    // 自底向上，子问题求解思路
    // int maxDepth(TreeNode* root) {
    //     if (!root) {
    //         return 0;
    //     }
    //     int leftDepth = maxDepth(root->left);
    //     int rightDepth = maxDepth(root->right);

    //     return 1 + max(leftDepth, rightDepth);
    // }
};
