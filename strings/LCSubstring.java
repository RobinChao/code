import java.util.*;

class LCString {
	Vector<String> substrings;

	String lcs(String a, String b) {
		if (a.length() == 0 || b.length() == 0)
			return "";

		int[][] lengths = new int[a.length()][];
		for (int i = 0; i < a.length(); ++i)
			lengths[i] = new int[b.length()];

		String ret = "";
		int max_len = 0;

		for (int i = 0; i < a.length(); ++i) {
			for (int j = 0; j < b.length(); ++j) {
				if (a.charAt(i) == b.charAt(j)) {
					if (i == 0 || j == 0) {
						lengths[i][j] = 1;
					}
					else {
						lengths[i][j] = lengths[i-1][j-1] + 1;
					}

					if (lengths[i][j] > max_len) {
						max_len = lengths[i][j];
						ret = a.substring(i-max_len+1, i+1);

						substrings = new Vector<String>();
						substrings.add(ret);
					}
					else if (lengths[i][j] == max_len){
						// other substrings of same size;
						substrings.add(a.substring(i-max_len+1, i+1));
					}
				}
				else {
					lengths[i][j] = 0;
				}
			}
		}

		return ret;
	}

	public static void main(String[] args) {
		String a = "abcdef";
		String b = "pqcde12";
		System.out.println("lcs(" + a + ", " + b + ") = " + new LCString().lcs(a,b));

		a = "abcdef";
		b = "cde";
		System.out.println("lcs(" + a + ", " + b + ") = " + new LCString().lcs(a,b));

		a = "abcdef";
		b = "pqr";
		System.out.println("lcs(" + a + ", " + b + ") = " + new LCString().lcs(a,b));

		a = "abcdef";
		b = "adef";
		System.out.println("lcs(" + a + ", " + b + ") = " + new LCString().lcs(a,b));

		a = "abcdef";
		b = "";
		System.out.println("lcs(" + a + ", " + b + ") = " + new LCString().lcs(a,b));

		a = "abcdefpqr";
		b = "abc1def2pqr";
		LCString s = new LCString();
		System.out.println("lcs(" + a + ", " + b + ") = " + s.lcs(a,b));

		Iterator<String> i = s.substrings.iterator();
		System.out.print("substrings = { " + i.next());
		while(i.hasNext()) {
			System.out.print(", " + i.next());
		} 
		System.out.println(" }");
	}
}