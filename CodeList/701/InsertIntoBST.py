# Definition for a binary tree node.

# Passed

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if not root: return root

        p = root
        while True:
            if p.val < val:
                if p.right:
                    p = p.right
                else:
                    node = TreeNode(val)
                    p.right = node        
                    return root
            elif p.val > val:
                if p.left:
                    p = p.left
                else:
                    node = TreeNode(val)
                    p.left = node
                    return root       