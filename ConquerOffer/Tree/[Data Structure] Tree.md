# [Data Structure] Tree

## [1] Tree Traversal

### Pre-order

- Traversal sequence [root, first child, second child, ..., N child]
  - Non-recursive

    ```c++
    void NonrecursivePre(TreeNode* root)
    {
        
    }
    ```

  - recursive

    ```c++
    vector<valueType> result;
    void RecursivePre(TreeNode* root)
    {
        result.push_back(root->val);
        RecursivePre(root->left);
        RecursivePre(root->right);
    }
    ```

### In-order

- Non-recursive
- recursive

### Rear-order

- Non-recursive
- recursive

### Level-order

