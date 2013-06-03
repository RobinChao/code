#include <iostream>
#include <string>

using namespace std;

/*	XY	= (Xl*2n/2 + Xr)(Yl*2n/2 + Yr)
 *		= 2n XlYl + 2n/2(XlYr + XrYl) + XrYr
 *		= 2n XlYl + 2n/2 * [(Xl + Xr)(Yl + Yr) - XlYl - XrYr] + XrYr
 *
 *	T(n) = 3T(n/2) + 
 */

int make_equal_length(string& a, string& b) {
	int len_a = a.size();
	int len_b = b.size();
	
	if (len_a  ==  len_b) 
		return len_a;
	else if (len_a > len_b) {
		for(int i = len_b; i < len_a; ++i)
			b = '0' + b;
		return len_a;
	}
	else {
		for(int i = len_a; i < len_b; ++i)
			a = '0' + a;
		return len_b;
	}
}

string add(string a, string b) {
	string result;
	int len = make_equal_length(a, b);
	int carry = 0;
	
	for (int i = len-1; i >= 0; --i) {
		int first_bit  = a[i] - '0';
		int second_bit = b[i] - '0';
		
		int sum = (first_bit ^ second_bit ^ carry) + '0';
		result = (char) sum + result;
		
		carry = (first_bit & second_bit) | (first_bit & carry) | (second_bit & carry);
	}
	
	if (carry)	result = '1' + result;	
	return result;
}

long int multiply(string a, string b) {
	int n = make_equal_length(a, b);
	
	if (n == 0)		return 0;
	if (n == 1)		return (a[0] - '0')*(b[0] - '0');
	
	int first_half	= n/2; 				// floor(n/2)
	int second_half	= n - first_half;	// ceil(n/2)
	
	string a_left	= a.substr(0, first_half);
	string a_right	= a.substr(first_half, second_half);
	
	string b_left	= b.substr(0, first_half);
	string b_right	= b.substr(first_half, second_half);
	long int p1 = multiply(a_left, b_left);
	long int p2 = multiply(a_right, b_right);
	
	string t1 = add(a_left, a_right);
	string t2 = add(b_left, b_right);
	long int p3 = multiply(t1, t2);
	
	return p1*(1 << (2*second_half)) + (p3 - p1- p2)*(1 << second_half) + p2;
}

int main() {
	cout << "multiply(\"111100\", \"1010\")	= " << multiply("111100", "1010") << endl;
	cout << "multiply(\"11011\", \"10100\") = " << multiply("11011", "10100") << endl;
	cout << "multiply(\"11\", \"1010\") = " << multiply("11", "1010") << endl;
	cout << "multiply(\"1\", \"11101\") = " << multiply("1", "11101") << endl;
	cout << "multiply(\"0\", \"11101\") = " << multiply("0", "11101") << endl;
	cout << "multiply(\"111\", \"111\") = " << multiply("111", "111") << endl;
	cout << "multiply(\"11\", \"11\") = " << multiply("11", "11") << endl;
	return 0;
}