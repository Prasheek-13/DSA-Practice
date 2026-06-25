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
    bool isIdentical(TreeNode* root, TreeNode* subroot) {
        if (root == NULL || subroot == NULL) {
            return root == subroot;
        }
        bool leftsame = isIdentical(root->left, subroot->left);
        bool rightsame = isIdentical(root->right, subroot->right);
        return leftsame && rightsame && root->val == subroot->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (root == NULL || subroot == NULL) {
            return root == subroot;
        }
        if (root->val == subroot->val && isIdentical(root, subroot)) {
            return true;
        }
        return isSubtree(root->left, subroot) ||
               isSubtree(root->right, subroot);
    }
};