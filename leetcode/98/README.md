# Validate Binary Search Tree

## Problem Summary

The goal of this problem is to determine if a given binary tree is a valid Binary Search Tree (BST). In a BST, for any given node:
- All values in the left subtree are less than the node's value.
- All values in the right subtree are greater than the node's value.
- Both left and right subtrees must also be BSTs.

**Input:**
- A pointer to the root of a binary tree.

**Output:**
- A boolean (`true` or `false`) indicating whether the tree is a valid BST.

## Detailed Approach and Rationale

The idea is to perform a recursive validation of each node. We use two additional parameters, `min` and `max`, to keep track of the valid range of values for each node. For the root node, `min` and `max` are set to the smallest and largest possible values, respectively.

### Recursive Validation:
1. **Base Case:** If the node is `NULL`, it is a valid BST.
2. **Boundary Checks:** If the current node's value is less than or equal to `min` or greater than or equal to `max`, it is not a valid BST.
3. **Recursive Call:** Validate the left subtree with the updated `max` value set to the current node's value. Validate the right subtree with the updated `min` value set to the current node's value.

The recursive function `validate` encapsulates this logic. The function `isValidBST` initializes the validation process by calling `validate` with appropriate `min` and `max` values.

## Time and Space Complexity

### Time Complexity:
- O(N), where N is the number of nodes in the tree. Each node is visited once.

### Space Complexity:
- O(H), where H is the height of the tree. This is due to the recursive stack space used during the depth-first traversal. In the worst case (skewed tree), this can be O(N), but in a balanced tree, it is O(log N).

## Key Test Cases

1. **Empty Tree:** The function should return `true` as an empty tree is a valid BST.
2. **Single Node Tree:** The function should return `true` if the single node follows BST properties.
3. **Valid BST with Multiple Nodes:** The function should return `true` for a correctly formed BST.
4. **Invalid BST due to Left Subtree Violation:** The function should return `false` if any node in the left subtree violates the BST properties.
5. **Invalid BST due to Right Subtree Violation:** The function should return `false` if any node in the right subtree violates the BST properties.
6. **Duplicate Values:** The function should return `false` if there are duplicate values in the tree.

## Extra Insights or Gotchas

- **Floating Point Precision:** When dealing with floating-point values, be cautious about equality checks.
- **Type Casting:** Ensure proper type casting, especially when dealing with boundary values (`min` and `max`). Using `long` helps to handle the extreme cases effectively.
- **Edge Cases Handling:** Remember to handle edge cases like `NULL` nodes and single-node trees carefully.

```c
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool validate(struct TreeNode* node, long min, long max) {
    if (!node) return true;
    if (node->val <= min || node->val >= max) return false;
    return validate(node->left, min, node->val) && validate(node->right, node->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}
```

These implementations handle the recursive validation efficiently, ensuring that each node is checked against its valid range.