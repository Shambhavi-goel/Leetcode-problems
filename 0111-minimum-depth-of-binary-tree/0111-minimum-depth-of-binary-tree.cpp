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
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        if(root-> left == nullptr && root-> right == nullptr){
            return 1;
        }
        long long int lheight= INT_MAX;
        long long int rheight= INT_MAX;
        if(root->left != nullptr){
        lheight= minDepth(root->left);
        }
        if(root->right != nullptr){
        rheight= minDepth(root->right);
        }
        long long int min_height= min(lheight, rheight);
        return (1 + min_height);
    }
};