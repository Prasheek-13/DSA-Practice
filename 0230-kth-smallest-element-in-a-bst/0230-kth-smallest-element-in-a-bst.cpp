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
    TreeNode* inorder(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        return root;
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        int n = ans.size();
        int finans = 0;
        if (k != 0) {
            finans = ans[k - 1];
        }
        if (k == 0) {
            return ans[0];
        }
        return finans;
    }
};