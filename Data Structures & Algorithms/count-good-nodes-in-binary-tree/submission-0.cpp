class Solution {
public:
    int dfs(TreeNode* node, int maxSoFar) {
        if (node == nullptr) return 0;
        int good = 0;
        if (node->val >= maxSoFar) {
            good = 1;
        }
        maxSoFar = max(maxSoFar, node->val);
        return good
            + dfs(node->left, maxSoFar)
            + dfs(node->right, maxSoFar);
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};