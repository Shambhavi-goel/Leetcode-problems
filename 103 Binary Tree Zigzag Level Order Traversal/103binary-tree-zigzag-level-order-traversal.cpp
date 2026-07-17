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
    void zigzag(TreeNode* root, vector<vector<int>> &res, int level){
        if(root==  nullptr){
            return;
        }
        if(res.size() <= level){
            res.push_back({});
        }
        if(level%2==0){
            res[level].push_back(root->val);
        }
        else{
            res[level].insert(res[level].begin(), root->val);
        }
        zigzag(root->left, res, level+1);
        zigzag(root->right, res, level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzag(root, res, 0);
        return res;
    }
};