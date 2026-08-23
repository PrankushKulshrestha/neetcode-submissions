class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int maxval){
        if (node==nullptr){
            return 0;
        }
        int count=0;
        if (node->val >= maxval){
            count=1;
        }
        maxval=max(maxval, node->val);
        count+=dfs(node->left, maxval);
        count+=dfs(node->right, maxval);
        return count;
    }
};
