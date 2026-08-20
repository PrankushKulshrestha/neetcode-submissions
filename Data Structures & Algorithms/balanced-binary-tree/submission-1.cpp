class Solution {
private:
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left == INT_MAX || right == INT_MAX) return INT_MAX;
        else if(left - right > 1 || left - right < -1) return INT_MAX;
        else return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(dfs(root) == INT_MAX) return false;
        else return true;
    }
};
