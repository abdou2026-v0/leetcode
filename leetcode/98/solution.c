/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool validate(struct TreeNode* node, long min, long max) {
    if (!node) return true;
    if (node->val <= min || node->val >= max) return false;
    return validate(node->left, min, node->val) && validate(node->right, node->val, max);
}

// bool isValidBST(struct TreeNode* root) {
//     return validate(root, LONG_MIN, LONG_MAX);
// }