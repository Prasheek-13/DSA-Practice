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
class info {
public:
    int min, max, size, sum;
    info(int mi, int ma, int sz, int s) {
        min = mi;
        max = ma;
        size = sz;
        sum = s;
    }
};
class Solution {
public:
    int ans = 0;
    info helper(TreeNode* root) {
        if (root == NULL) {
            return info(INT_MAX, INT_MIN, 0, 0);
        }
        info left = helper(root->left);
        info right = helper(root->right);
        if (root->val > left.max && root->val < right.min) {
            int currmin = min(root->val, left.min);
            int currmax = max(root->val, right.max);
            int currsize = left.size + right.size + 1;
            int currsum = left.sum + right.sum + root->val;
            ans = max(ans, currsum);

            return info(currmin, currmax, currsize, currsum);
        }
        return info(INT_MIN, INT_MAX, max(left.size, right.size),
                    max(left.sum, right.sum));
    }

    int maxSumBST(TreeNode* root) {
        info Info = helper(root);
        return ans;
    }
};