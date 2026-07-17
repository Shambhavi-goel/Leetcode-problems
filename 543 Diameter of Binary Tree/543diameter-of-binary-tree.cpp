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
int maxdiameter=0;
class Solution {
public:
    int diameter(TreeNode* root){
        if(!root){
            return 0;
        }
        int lheight= diameter(root->left);
        int rheight= diameter(root->right);

        if((lheight+rheight)>maxdiameter){
            maxdiameter= lheight + rheight;
        }

        return 1+ max(lheight, rheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxdiameter=0;
        diameter(root);
        return maxdiameter;
    }
};