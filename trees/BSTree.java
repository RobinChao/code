import java.util.Comparator;
import java.util.Random;
import java.util.ArrayList;

class Node<T extends Comparable<T>> {
  T key;
  Node<T> left, right;

  Node() {
    this.left = null;
    this.right = null;
  }

  Node(T x) {
    super();
    this.key = x;
  }
}

class BSTree<T extends Comparable<T>> {
  Node<T> root;
  Comparator<T> comparator;

  BSTree() {
    this.comparator = null;
    this.root = null;
  }

  BSTree(Comparator<T> comparator) {
    this.comparator = comparator;
    this.root = null;
  }

  private int compare(T x, T y) {
    if (comparator == null)
      return x.compareTo(y);
    else
      return comparator.compare(x, y);
  }

  void insert(T key) {
    root = insert(root, key);
  }

  private Node<T> insert(Node<T> node, T key) {
    if (node == null) {
      return new Node<T>(key);
    }
    else if (compare(key, node.key) < 0) {
      node.left = insert(node.left, key);
    }
    else if (compare(key, node.key) > 0) {
      node.right = insert(node.right, key);
    }
    else {
      System.err.println("Element " + key + " is already in the BST !");
    }
    return node;
  }

  void remove(T key) {
    this.root = remove(this.root, key);
  }

  private Node<T> remove(Node<T> node, T key) {
    if (node == null) {
      System.err.println("Element " + key + " is not present in the BST !");
    }
    else if (compare(key, node.key) < 0) {
      node.left = remove(node.left, key);
    }
    else if (compare(key, node.key) > 0) {
      node.right = remove(node.right, key);
    }
    else {
      if (node.left == null)        node = node.right;
      else if (node.right == null)  node = node.left;
      else {
        T rightSuccessorKey = getMin(node.right);
        node.key = rightSuccessorKey;
        node.right = remove(node.right, rightSuccessorKey);
      }
    }
    return node;
  }

  private T getMin(Node<T> node) {
    if (node == null)   return null;
    while (node.left != null) {
      node = node.left;
    }
    return node.key;
  }

  void printInOrder() {
    if (root == null) {
      System.err.println("Tree is empty !");
    }
    else {
      printInOrder(root);
      System.out.println();
    }
  }

  private void printInOrder(Node<T> node) {
    if (node == null)   return;
    printInOrder(node.left);
    System.out.print(" " + node.key);
    printInOrder(node.right);
  }

  public static void main (String [] args) {
    BSTree<Integer> bst = new BSTree<Integer>();

    Random random = new Random();

    int numNodes = 10;
    System.out.println("Number of nodes = " + numNodes);

    ArrayList<Integer> list = new ArrayList<Integer>();
    boolean[] deleted = new boolean[numNodes];

    for (int i = 0; i < numNodes; i++) {
      int num = random.nextInt(1000);
      list.add(num);
      deleted[i] = false;

      System.out.println("Element to be inserted: " + num);
      bst.insert(num);
      bst.printInOrder();
    }

    for(int i = 0; i < numNodes; i++) {
      int index = random.nextInt(numNodes);
      while (deleted[index]) {
        index = random.nextInt(numNodes);
      }

      deleted[index] = true;

      int num = list.get(index);

      System.out.println("Element to be deleted: " + num);
      bst.remove(num);
      bst.printInOrder();
    }
  }
}
