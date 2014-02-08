#include <queue>
#include <iostream>
#include <string>

using namespace std;

string* top_k(string* list, int n, int k) {

	priority_queue<string, vector<string>, greater<string> > q;

	k = k > n ? n : k;
	for(int i = 0; i < n; ++i) {
		if (i < k) {
			q.push(list[i]);
		}
		else {
			if (q.top() < list[i]) {
				q.pop();
				q.push(list[i]);
			}
		}
	}

	string* res = new string[k];
	for (int i = 0; i < k; ++i) {
		res[k - i - 1] = q.top();
		q.pop();
	}

	return res;
}

int main() {
	string arr[] = { "Beta", "Alpha", "Kappa", "Gamma", "Zeta", "Iota", "Eta", "Tau", "Phi", "Pi" };

	string* res = top_k(arr, 10, 5);
	for (int i = 0; i < 5; ++i) {
		cout << res[i] << " ";
	}
	
	return 0;
}
