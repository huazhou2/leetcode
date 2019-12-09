# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def helper(preorder,inorder):
            if not preorder:
                return None
            root=preorder.pop(0)
            head=TreeNode(root)
            ind=inorder.index(root)
            head.left=helper(preorder,inorder[:ind])
            head.right=helper(preorder,inorder[ind+1:])
            return head
        return helper(preorder,inorder)

