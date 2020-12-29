# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# class Solution:
#     def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        # sum = 0
        # if L <= root.val and root.val <= R:
        #     sum += root.val
        # if root.left:
        #     sum += self.rangeSumBST(root.left, L, R)
        # if root.right:
        #     sum += self.rangeSumBST(root.right, L, R)
        # return sum
        