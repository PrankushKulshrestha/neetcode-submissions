class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            std::swap(node->left, node->right);
            if(node->right) queue.push(node->right);
            if(node->left) queue.push(node->left);
        }
        return root;
    }
};
