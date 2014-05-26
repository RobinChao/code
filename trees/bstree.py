import random

class BinaryTreeNode:
  """Binary Tree Node"""
  def __init__(self, key, left=None, right=None):
    self.key = key
    self.left = left
    self.right = right

class BinarySearchTree:
  """Binary Search Tree"""
  def __init__(self, root=None):
    self.root = root

  def insert(self, key):
    success, self.root = self._insert(self.root, key)
    if success:
      print 'key', key, 'inserted into the bst'
    else:
      print 'key', key, 'already present'

  def _insert(self, node, key):
    if node is None:
      return True, BinaryTreeNode(key)
    if node.key == key:
      return False, node
    else:
      if node.key > key:
        success, node.left = self._insert(node.left, key)
      else:
        success, node.right = self._insert(node.right, key)
      return success, node
  
  def get_successor(self, node):
    if node.right is None:
      return None
    node = node.right
    while node.left is not None:
      node = node.left
    return node

  def remove(self, key):
    success, self.root = self._remove(self.root, key)
    if success:
      print 'key', key, 'removed from the bst'
    else:
      print 'key', key, 'not present'

  def _remove(self, node, key):
    if node is None:
      return False, node
    if node.key == key:
      if node.left is not None and node.right is not None:
        successor = self.get_successor(node)
        node.key = successor.key
        success, node.right = self._remove(node.right, successor.key)
        return True, node
      elif node.left is not None:
        return True, node.left
      else:
        return True, node.right
    else:
      if node.key > key:
        success, node.left = self._remove(node.left, key)
      else:
        success, node.right = self._remove(node.right, key)
      return success, node

  def inorder(self):
    if self.root is None:
      print 'Empty tree !'
    else:
      self._inorder(self.root)
      print

  def _inorder(self, node):
    if node is not None:
      self._inorder(node.left)
      print node.key,
      self._inorder(node.right)
   

if __name__ == '__main__':
  tree = BinarySearchTree();
  tree.inorder()
  n = 50
  for i in xrange(n):
    tree.insert(random.randint(1, n))
    tree.inorder()
  for i in xrange(n*n):
    tree.remove(random.randint(1, n))
    tree.inorder()
