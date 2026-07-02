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
            return 0;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        return root;
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);

        int n = ans.size();
        int finans = INT_MAX;
        while (n >= 2) {
            finans = min(finans, (ans[n - 1] - ans[n - 2]));
            n--;
        }
        return finans;
    }
};