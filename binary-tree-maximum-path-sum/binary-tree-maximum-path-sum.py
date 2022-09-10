# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.max = -1000000000
        
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.max
    
    def dfs(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        subtree_total = left + root.val + right
        print("subtree {}".format(subtree_total))
        self.max = max(subtree_total, self.max)
        a = max(left, right) + root.val
        b = root.val
        no_subtree_total = max(a, b)
        self.max = max(no_subtree_total, self.max)
        return no_subtree_total