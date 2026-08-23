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
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }

    bool isValid(TreeNode* node, int lo, int hi) {
        if(node == nullptr) {
            return true;
        }
        int now = node->val;
        if(now <= lo || now >= hi) {
            return false;
        }
        bool left = isValid(node->left, lo, min(hi, now));
        bool right = isValid(node->right, max(lo, now), hi);
        return left && right;
    }
};
