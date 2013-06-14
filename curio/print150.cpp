#include <iostream>
using namespace std;

template<int N>
struct NumberGeneration {
	static void out(ostream& os) {
		NumberGeneration<N-1>::out(os);
		os << N << endl;
	}
};

template<>
struct NumberGeneration<1> {
	static void out(ostream& os) {
		os << 1 << endl;
	}
};

int main() {
	NumberGeneration<150>::out(cout);
}