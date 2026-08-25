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
    int neg = -10000;
    int rec(TreeNode* root, int sum, int & max_sum ){
        if(!root) return neg;
        int left = rec(root -> left, sum, max_sum);
        int right = rec(root -> right, sum, max_sum);
        int lr = max(left, right);
        int val = root -> val;
        int suum = max(val, val + lr);
        max_sum = max(max_sum, max(suum, left + right + val));
        return suum; 
    }
    int maxPathSum(TreeNode* root) {
        int sum = 0;
        int max_sum = INT_MIN;
        rec(root, sum, max_sum);
        return max_sum;
    }
};
