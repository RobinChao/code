import java.util.Arrays;
import java.util.Random;

public class Sorting {
  public static void quicksort(int[] array) {
    qsort(array, 0, array.length - 1);
  }

  private static void qsort(int[] array, int hi, int lo) {
    if (lo >= hi)  return;
    int partitionIndex = (lo + hi)/2;
    int sortedPartitionIndex = partition(array, partitionIndex, hi, lo);
    qsort(array, lo, sortedPartitionIndex - 1);
    qsort(array, sortedPartitionIndex + 1, hi);
  }

  private static int partition(int[] array, int index, int hi, int lo) {
    int pivot = array[index];
    int i = lo, j = hi;
    while (i < j) {
      while (array[i] < pivot)  i++;
      while (array[j] > pivot)  j--;
      swap(array, i, j);
    }
    return i-1;
  }

  private static void swap(int[] array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  }

  public static boolean testSorting(String algorithm) {
    Random random = new Random();
    int N = random.nextInt(100);
    int[] array = new int[N];
    for (int x : array) {
      x = random.nextInt(1000);
    }

    int[] copiedArray = Arrays.copyOf(array, array.length);

    if (algorithm.equals("quicksort"))
      Sorting.quicksort(array);
    else
      return false;
    Arrays.sort(copiedArray);

    for (int i = 0; i < array.length; i++) {
      if (array[i] != copiedArray[i]) 
        return false;
    }

    return true;
  }

  public static void main (String [] args) {
    System.out.println("sorting result = " + Sorting.testSorting("quicksort"));
  }
}
