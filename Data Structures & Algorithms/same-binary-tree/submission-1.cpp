class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q ^ !p) return false;
        if(!q && !p) return true;
        bool sameVal = q->val == p->val;
        bool restSame = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return sameVal && restSame;
    }
};