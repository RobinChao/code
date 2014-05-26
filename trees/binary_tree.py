import sys

class BinaryTreeNode(object):
  """Binary Tree"""
  def __init__(self, key, left=None, right=None):
    super(BinaryTreeNode, self).__init__()
    self.key = key
    self.left = left
    self.right = right

def count(root):
  if root is None:
    return 0
  lcount = count(root.left)
  rcount = count(root.right)
  return lcount + rcount + 1

def inorder(root):
  if root is not None:
    inorder(root.left)
    print root.key,
    inorder(root.right)

def is_bstree(root):
  if root is None:
    return True
  if root.left is not None:
    if root.key < root.left.key:
      return False
  if root.right is not None:
    if root.key > root.right.key:
      return False
  return is_bstree(root.left) and is_bstree(root.right)

if __name__ == '__main__':
  root = None
  print is_bstree(root)

  root = BinaryTreeNode(50, None, None)
  print is_bstree(None)

  root.left = BinaryTreeNode(30, None)
  root.left.right = BinaryTreeNode(40)
  inorder(root)
  print
  print is_bstree(root)

  root.left.right.left = BinaryTreeNode(100)
  inorder(root)
  print
  print is_bstree(root)
  
  print 'count =', count(root)
