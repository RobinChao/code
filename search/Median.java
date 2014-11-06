import java.util.PriorityQueue;
import java.util.Collections;
import java.util.Scanner;
import java.util.Random;
import java.util.Comparator;
import java.util.ArrayList;

/*
 * Track median over streaming numbers
 */

public class Median {

  Integer[] medians;
  PriorityQueue<Integer> lowerHalf;
  PriorityQueue<Integer> upperHalf;
  int count;

  public Median() {
    this.count = 0;
    
    this.medians = new Integer[2];
    this.medians[0] = null;
    this.medians[1] = null;
    
    this.lowerHalf = new PriorityQueue<Integer>(10, new Comparator<Integer>() {
        @Override
        public int compare(Integer x, Integer y) {
          return y.compareTo(x);  // Min-Heap
        }
      }); 

    this.upperHalf = new PriorityQueue<Integer>(10, new Comparator<Integer>() {
        @Override
        public int compare(Integer x, Integer y) {
          return x.compareTo(y);  // Min-Heap
        }
      }); 
  }

  void updateMedian(Integer element) {
    Integer maxLowerHalf = lowerHalf.peek();
    if (maxLowerHalf == null) {
      lowerHalf.add(element);
    }
    else if (maxLowerHalf.compareTo(element) >= 0) {
      lowerHalf.add(element);
      if (lowerHalf.size() > upperHalf.size() + 1) {
        Integer polledElement = lowerHalf.poll();
        upperHalf.add(polledElement);
      }
    }
    else {
      upperHalf.add(element);
      if (upperHalf.size() > lowerHalf.size() + 1) {
        Integer polledElement = upperHalf.poll();
        lowerHalf.add(polledElement);
      }
    }

    this.count++;
    if (count % 2 == 0) {
      this.medians[0] = this.lowerHalf.peek();
      this.medians[1] = this.upperHalf.peek();
    }
    else {
      if (lowerHalf.size() > upperHalf.size()) {
        this.medians[0] = this.lowerHalf.peek();
      }
      else {
        this.medians[0] = this.upperHalf.peek();
      }
      this.medians[1] = null;
    }
  }

  @Override
  public String toString() {
    if (this.count == 0)  return null;
    return medians[0].toString() + (medians[1] != null ? " " + medians[1].toString() : "");
  }

  public static void main (String [] args) {
    Median median = new Median();
    Random random = new Random();
    Scanner scanner = new Scanner(System.in);
    int testCases = 100;
    ArrayList<Integer> list = new ArrayList<Integer>();

    for (int caseNum = 0; caseNum < testCases; caseNum++) {
      Integer num = random.nextInt(10000);
      System.out.println("Element inserted: " + num);

      median.updateMedian(num);
      System.out.println("Actual Medians:   " + median);

      list.add(num);
      Collections.sort(list);
      System.out.print("Case: #" + caseNum + ": ");
      if (list.size() % 2 == 0) {
        Integer median0 = list.get(list.size()/2 - 1);
        Integer median1 = list.get(list.size()/2);
        // System.out.println("Expected Medians: " + median0 + " " + median1);
        System.out.println((median0.equals(median.medians[0]) && median1.equals(median.medians[1])));
      }
      else {
        Integer median0 = list.get(list.size()/2);
        // System.out.println("Expected Medians: " + median0);
        System.out.println(median0.equals(median.medians[0]));
      }
    }
  }
}
