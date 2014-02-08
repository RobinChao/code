import java.util.*;

class TopK {

	String[] topK(String[] list, int k) {
		PriorityQueue<String> q = new PriorityQueue<String>();

		k = k > list.length ? list.length : k;

		for (int i = 0; i < list.length; ++i) {
			if (i >= k) {
				if (list[i].compareTo(q.peek()) > 0 ) {
					q.poll();
					q.add(list[i]);
				}
			}
			else {
				q.add(list[i]);
			}
		}

		String[] res = new String[k];
		for (int i = 0; i < k; ++i) {
			res[k - i - 1] = q.poll();
		}

		return res;
	}

	String[] naiveTopK(String[] list, int k) {
		Arrays.sort(list);

		k = k > list.length ? list.length : k;
		String[] ret = new String[k];
		for (int i = 0; i < k; ++i) {
			ret[i] = list[list.length - i - 1];
		}

		return ret;
	}

	public static void main(String[] args) {
		String[] arr = { "Beta", "Alpha", "Kappa", "Gamma", "Zeta", "Iota", "Eta", "Tau", "Phi", "Pi" };

		String[] res = new TopK().naiveTopK(arr, 5);
		System.out.print("res = { " + res[0]);
		for (int i = 1; i < res.length; ++i) {
			System.out.print(", " + res[i]);
		}
		System.out.println(" }");

		res = new TopK().topK(arr, 6);
		System.out.print("res = { " + res[0]);
		for (int i = 1; i < res.length; ++i) {
			System.out.print(", " + res[i]);
		}
		System.out.println(" }");
	}
}