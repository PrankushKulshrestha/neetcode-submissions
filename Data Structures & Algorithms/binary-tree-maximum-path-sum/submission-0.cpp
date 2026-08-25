class Solution {
public:
    int ans = INT_MIN;
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));
        ans = max(ans, node->val + left + right);
        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};