#!/usr/bin/python
#-*-coding: utf8-*-

# Definition for a  binary tree node


class TreeNode:

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # @param root, a tree node
    # @return a list of integers

    def postorderTraversal(self, root):
        stack = []
        result = []

        if root is None:
            return result

        stack.append(root)
        pre = None

        while len(stack) > 0:
            p = stack[-1]
            
            if p.left is None and p.right is None:
                result.append(p.val)
                pre = p
                stack.pop()
            elif pre is not None and (pre == p.left or pre == p.right):
                result.append(p.val)
                pre = p
                stack.pop()
            else:
                if p.right is not None:
                    stack.append(p.right)

                if p.left is not None:
                    stack.append(p.left)
        return result

if __name__ == "__main__":
    node = TreeNode(1)
    node.right = TreeNode(2)
    node.right.left = TreeNode(3)
    s = Solution()
    s.postorderTraversal(node)
