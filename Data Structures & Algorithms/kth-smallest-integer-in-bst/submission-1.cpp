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
    int ans;
    int count;
    int kthSmallest(TreeNode* root, int k) {
        ans = 0;
        count = 0;
        travel(root,k);
        return ans;
    }

    void travel(TreeNode* root, int k){

        if(root == nullptr) return;
        travel(root->left,k);
        count ++;
        if(k == count){
            ans = root->val;
            return;
        } 
        travel(root->right,k);
    }
};
