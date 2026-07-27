#/bin/python3

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countDominantNodes(self, root: TreeNode | None) -> int:
        # ©leetcode
        if not root:
            return 0
        count = 0
        
        # 后续遍历
        def postorder(node: TreeNode | None) -> int:
            nonlocal count
            if not node:
                return float('-inf')
            left_max = postorder(node.left)
            right_max = postorder(node.right)
            if node.val >= left_max and node.val >= right_max:
                count += 1
            return max(node.val, left_max, right_max)
        postorder(root)
        return count

if __name__ == "__main__":
    s = Solution()
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(8)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(7)
    root.right.right = TreeNode(1)
    print(s.countDominantNodes(root))
