class Solution {
public:
    bool dfs(TreeNode* node, long long low, long long high) {
        if (node == nullptr) {
            return true;
        }
        if (node->val <= low || node->val >= high) {
            return false;
        }
        return dfs(node->left, low, node->val) &&
               dfs(node->right, node->val, high);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};