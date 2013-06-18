#include <iostream>
#include <cstring>

using namespace std;

// coin change problem with unlimited no of coins

int count(int* coins, int m, int n) {
	if (n == 0)		return 1;
	if (n < 0)		return 0;
	if (m <= 0)		return 0;
	
	// count is sum of solutions -- 1. including coins[m-1], 2. excluding coins[m-1]
	return count(coins, m-1, n) + count(coins, m, n - coins[m-1]);	
} 

int count_d(int* coins, int m, int n) {
    // table[i] will be storing the number of solutions for value i. 
	// We need n+1 rows as the table is consturcted in bottom up manner using the base case (n = 0)
    int* table = new int [n+1];
 
    memset(table, 0, sizeof(int)*(n+1));
	table[0] = 1; // Base case (If given value is 0)
 
    // Pick all coins one by one and update the table[] values after the index greater 
	// than or equal to the value of the picked coin
    for(int i = 0; i < m; i++)
        for(int j = coins[i]; j <= n; j++)
            table[j] += table[j - coins[i]];
	
	int ret_val = table[n];
	delete [] table;
    return ret_val;
}

int main() {
	int coins[] = {1, 2, 3};
	cout << "count(coins, 3, 4) = " << count(coins, 3, 4) << endl;
	cout << "count(coins, 3, 10) = " << count(coins, 3, 10) << endl;
	cout << "count_d(coins, 3, 30) = " << count_d(coins, 3, 30) << endl;
	cout << "count_d(coins, 3, 10) = " << count_d(coins, 3, 10) << endl;
	return 0;
}