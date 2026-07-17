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
    int search(vector<int> inorder, int value, int left, int right){
        for(int i=left; i<=right; i++){
            if(value== inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &preIdx, int left, int right) {
        if(left > right){
            return nullptr;
        }
        TreeNode* root= new TreeNode(preorder[preIdx]);

        int inIdx= search(inorder, preorder[preIdx], left, right);
        preIdx++;

        root->left= build(preorder, inorder, preIdx, left, inIdx-1);
        root->right= build(preorder, inorder, preIdx, inIdx+1, right);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx=0;
        return build(preorder, inorder, preIdx, 0, inorder.size()-1);
    }
};