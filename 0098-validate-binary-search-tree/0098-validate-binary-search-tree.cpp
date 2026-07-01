/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans = {};
    bool isValidBST(TreeNode* root) {

        if (root == NULL) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        ans.push_back(root->val);
        int n = ans.size();
        if (ans.size() > 1 && ans[n - 2] >= ans[n - 1]) {
            return false;
        }
        if (!isValidBST(root->right)) {
            return false;
        }
        return true;
    }
};