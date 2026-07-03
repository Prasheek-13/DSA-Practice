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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> Root1;
        vector<int> Root2;
        inorder(root1, Root1);
        inorder(root2, Root2);
        vector<int> result;
        int i = 0, j = 0;
        while (i < Root1.size() && j < Root2.size()) {
            if (Root1[i] < Root2[j]) {
                result.push_back(Root1[i++]);
            } else {
                result.push_back(Root2[j++]);
            }
        }
        while (i < Root1.size()) {
            result.push_back(Root1[i++]);
        }
        while (j < Root2.size()) {
            result.push_back(Root2[j++]);
        }
        /* merge(Root1.begin(), Root1.end(), Root2.begin(), Root2.end(),
               back_inserter(result));*/
        return result;
    }
};