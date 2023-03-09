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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        traverse(root, maxD);
        return maxD;
    }
    
    int traverse(TreeNode* root, int& maxD) {
        if (!root) {
            return 0;
        }
        
        int dL = traverse(root->left, maxD);
        int dR = traverse(root->right, maxD);
        
        maxD = max(dL + dR, maxD);
        
        return 1 + max(dL, dR);
    }
};
