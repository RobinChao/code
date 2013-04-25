#include <iostream>

using namespace std;

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

long int multiply(string& a, string& b){
	int n = make_equal_length(a, b);
	
	if (n == 0)		return 0;
	if (n == 1)		return (a[0] - '0')*(b[0] - '0');
	
	int first_half	= n/2; 				// floor(n/2)
	int second_half	= n - first_half;	// ceil(n/2)
	
	string a_left	= a.substr(0, first_half);
	string a_right	= a.substr(second_half, n);
	
	string b_left	= b.substr(0, first_half);
	string b_right	= b.substr(second_half, n);
	
	long int p1 = multiply(a_left, b_left);
	long int p2 = multiply(a_right, b_right);
	long int p3 = multiply(add(a_left, a_right), add(b_left, b_right));
	
}

int main() {
	
	return 0;
}