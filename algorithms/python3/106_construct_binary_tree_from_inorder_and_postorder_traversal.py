# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def helper(inorder, postorder):
            if not inorder:
                return None
            root = postorder.pop()
            head = TreeNode(root)
            ind = inorder.index(root)
            head.left = helper(inorder[:ind], postorder[:ind])
            head.right = helper(inorder[ind + 1:], postorder[ind:])
            return head

        return helper(inorder, postorder)
