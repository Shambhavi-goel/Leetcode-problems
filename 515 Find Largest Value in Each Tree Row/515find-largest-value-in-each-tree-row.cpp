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
    void levelo(TreeNode* root, int level, vector<vector<int>> &res){
        if(root== nullptr){
            return;
        }
        if(res.size() <= level){
            res.push_back({});
        }
        res[level].push_back(root->val);

        levelo(root->left, level+1, res);
        levelo(root->right, level+1, res);

    }
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> ans;
        levelo(root,0,res);

        for(int i=0; i< res.size(); i++){
        ans.push_back(*max_element(res[i].begin(), res[i].end()));}
        return ans;
    }
};