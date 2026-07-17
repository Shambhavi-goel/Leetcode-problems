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
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int &postIdx, int left, int right) {
        if(left > right){
            return nullptr;
        }
        TreeNode* root= new TreeNode(postorder[postIdx]);

        int inIdx= search(inorder, postorder[postIdx], left, right);
        postIdx--;

        root->right= build(postorder, inorder, postIdx, inIdx+1, right);
        root->left= build(postorder, inorder, postIdx, left, inIdx-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx=postorder.size()-1;
        return build(postorder, inorder, postIdx, 0, inorder.size()-1);
    }
};