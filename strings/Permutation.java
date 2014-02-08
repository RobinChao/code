import java.util.*;

class Permutation {
	Vector<String> permutations;
	String string;

	Permutation(String string) {
		this.string = string;
		permutations = new Vector<String>();
	}

	void permute() {
		permuteInner(string.toCharArray(), 0);
	} 

	void swap(char[] str, int n, int i) {
		char tmp = str[n];
		str[n] = str[i];
		str[i] = tmp;
	}

	void permuteInner(char[] str, int n){
		if (n == str.length) {
			permutations.add(new String(str));
		}
		else {
			for(int i = n; i < str.length; i++) {
				swap(str, n, i);
				permuteInner(str, n+1);
				swap(str, i, n);
			}
		}
	}

	void permuteWithDuplicates() {
		char[] str = string.toCharArray();
		// Arrays.sort(str); // --- not needed with boolean[] visited_char
		permuteWithDuplicatesInner(str, 0);
	}

	void permuteWithDuplicatesInner(char[] str, int n){
		boolean[] visited_char = new boolean[256];

		if (n == str.length) {
			permutations.add(new String(str));
		}
		else {
			for(int i = n; i < str.length; i++) {
				if(visited_char[str[i]])	
					continue;
				else 
					visited_char[str[i]] = true;
				
				swap(str, n, i);
				permuteWithDuplicatesInner(str, n+1);
				swap(str, i, n);
			}
		}
	}

	public String toString() {
		String res = "";
		Iterator<String> i = permutations.iterator();
		String str = "";
		str += string + " : " + i.next();
		
		while (i.hasNext()) {
			str += ", " + i.next();
		}

		return str;
	}

	public static void main(String[] args) {
		Permutation p1 = new Permutation("abc");
		p1.permute();
		System.out.println(p1);

		p1 = new Permutation("abcd");
		p1.permute();
		System.out.println(p1);

		p1 = new Permutation("abcde");
		p1.permute();
		System.out.println(p1);

		p1 = new Permutation("");
		p1.permute();
		System.out.println(p1);

		p1 = new Permutation("a");
		p1.permute();
		System.out.println(p1);

		p1 = new Permutation("aba");
		p1.permute();
		System.out.println(p1);

		p1 = new Permutation("baaaaa");
		p1.permuteWithDuplicates();
		System.out.println(p1);

		p1 = new Permutation("baac");
		p1.permuteWithDuplicates();
		System.out.println(p1);
	}
}