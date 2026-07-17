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
    int depth(TreeNode* root){
        if(root== nullptr){
            return -1;
        }
        int lheight= depth(root->left);
        int rheight= depth(root->right);
        return max(lheight, rheight)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root== nullptr){
            return true;
        }
        int lheight= depth(root->left);
        int rheight= depth(root->right);
        if(abs(lheight - rheight) > 1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};