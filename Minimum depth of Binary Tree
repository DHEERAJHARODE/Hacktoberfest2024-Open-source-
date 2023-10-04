class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        l = self.minDepth(root.left)
        r = self.minDepth(root.right)
        
        if root.left and root.right:
            return min(l, r) + 1
        
        return max(l, r) + 1
