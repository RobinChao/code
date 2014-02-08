import java.util.*;

class PermuteK {
	Vector<String> permutations;
	char[] alphabet;

	PermuteK(char[] alphabet) {
		this.alphabet = alphabet;
		permutations = new Vector<String>();
	}

	PermuteK(String alphabet) {
		this.alphabet = alphabet.toCharArray();
		permutations = new Vector<String>();
	}

	// find all strings of length k
	void permute(int k) {
		permuteInner("", k);
	}

	void permuteInner(String prefix, int k) {
		if (k == 0) {
			permutations.add(prefix);
			return;
		}

		for (int i = 0; i < alphabet.length; ++i) {
			String new_prefix = prefix + alphabet[i];
			permuteInner(new_prefix, k-1);
		}
	}

	public String toString() {
		String res = "";
		Iterator<String> i = permutations.iterator();
		String str = "";
		str += new String(alphabet) + " : " + i.next();
		
		while (i.hasNext()) {
			str += ", " + i.next();
		}

		return str;
	}

	public static void main(String[] args) {
		PermuteK p1 = new PermuteK("ab");
		int k = 4;
		p1.permute(k);
		System.out.println("p1.permute() = " + p1);

		p1 = new PermuteK("abcdef");
		k = 1;
		p1.permute(k);
		System.out.println("p1.permute() = " + p1);

		p1 = new PermuteK("abc");
		k = 3;
		p1.permute(k);
		System.out.println("p1.permute() = " + p1);
	}
}